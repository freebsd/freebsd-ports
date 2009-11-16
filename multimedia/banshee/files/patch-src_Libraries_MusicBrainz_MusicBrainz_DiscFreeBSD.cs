
$FreeBSD$

--- /dev/null
+++ src/Libraries/MusicBrainz/MusicBrainz/DiscFreeBSD.cs
@@ -0,0 +1,134 @@
+// DiskFreeBSD.cs
+// 
+// Copyright (c) 2009 Romain Tartière <romain@blogreen.org>
+//
+// Permission is hereby granted, free of charge, to any person obtaining a copy
+// of this software and associated documentation files (the "Software"), to deal
+// in the Software without restriction, including without limitation the rights
+// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
+// copies of the Software, and to permit persons to whom the Software is
+// furnished to do so, subject to the following conditions:
+//
+// The above copyright notice and this permission notice shall be included in
+// all copies or substantial portions of the Software.
+//
+// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
+// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
+// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
+// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
+// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
+// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
+// THE SOFTWARE.
+
+using System;
+using System.Runtime.InteropServices;
+
+namespace MusicBrainz
+{
+	internal sealed class DiscFreeBSD : LocalDisc
+	{
+	
+#region <fcntl.h>
+		const int O_RDONLY   = 0x0000;	// open for reading only
+		const int O_NONBLOCK = 0x0004;	// no delay
+
+		[DllImport ("libc.so.7", CharSet = CharSet.Auto, SetLastError = true)]
+		static extern int open (string path, int flags);
+#endregion
+		
+#region <unistd.h>
+		[DllImport ("libc.so.7", SetLastError = true)]
+		static extern int close (int d);
+#endregion
+
+#region <sys/cdio.h>
+		struct msf_lba {
+			public int lba;	// network byte order
+		};
+		
+		[StructLayout (LayoutKind.Explicit)]
+		struct cd_toc_entry {
+			[FieldOffset (2)]
+			public byte track;
+			[FieldOffset (4)]
+			public msf_lba addr;
+		};
+		
+		// Ioctls for the CD drive
+		
+		const byte CD_LBA_FORMAT = 1;
+		
+		struct ioc_toc_header {
+			public short len;
+			public byte starting_track;
+			public byte ending_track;
+		};
+		const ulong CDIOREADTOCHEADER = 1074029316;
+		[DllImport ("libc.so.7", EntryPoint = "ioctl")]
+        static extern int cd_read_toc_header (int fd, ulong request, ref ioc_toc_header data);
+        static int cd_read_toc_header (int fd, ref ioc_toc_header data)
+        {
+            return cd_read_toc_header (fd, CDIOREADTOCHEADER, ref data);
+        }
+		
+		struct ioc_read_toc_entry {
+			public byte address_format;
+			public byte starting_track;
+			public ushort data_len;
+			public IntPtr data; // cd_toc_entry*
+		};
+		const ulong CDIOREADTOCENTRYS = 3222299397;
+		[DllImport ("libc.so.7", EntryPoint = "ioctl")]
+        static extern int cd_read_toc_entrys (int fd, ulong request, ref ioc_read_toc_entry data);
+        static int cd_read_toc_entrys (int fd, ref ioc_read_toc_entry data)
+        {
+            return cd_read_toc_entrys (fd, CDIOREADTOCENTRYS, ref data);
+        }
+		
+#endregion
+		
+		internal DiscFreeBSD (string device)
+		{
+			int fd = open (device, O_RDONLY | O_NONBLOCK);
+			
+			if (fd < 0) throw new LocalDiscException (String.Format ("Cannot open device `{0}'", device));
+			
+			try {
+				ioc_toc_header h = new ioc_toc_header ();
+				if (cd_read_toc_header (fd, ref h) < 0) throw new LocalDiscException ("Cannot read table of contents header");
+				if (h.ending_track == 0) throw new LocalDiscException ("This disc has no tracks");
+				
+				first_track = h.starting_track;
+				last_track = h.ending_track;
+				
+				int n = h.ending_track - h.starting_track + 1;
+				int len = (n + 1) * Marshal.SizeOf (typeof (cd_toc_entry));
+				
+				ioc_read_toc_entry t = new ioc_read_toc_entry ();
+				t.address_format = CD_LBA_FORMAT;
+				t.starting_track = 0;
+				t.data_len = (ushort) len;
+				t.data = Marshal.AllocHGlobal (len);
+				try {
+				
+					if (cd_read_toc_entrys (fd, ref t) < 0) throw new LocalDiscException ("Cannot read table of contents entries");
+				
+                	for (int i = 0; i <= n; i++) {
+						ulong offset = (ulong) (i * Marshal.SizeOf (typeof (cd_toc_entry)));
+                		cd_toc_entry e = (cd_toc_entry) Marshal.PtrToStructure ((IntPtr) ((ulong)t.data + offset), typeof (cd_toc_entry));
+    	                track_offsets[first_track + i] = System.Net.IPAddress.NetworkToHostOrder (e.addr.lba) + 150;
+        	        }
+					// Move Leadout to the beginning.
+        	        track_offsets [0] = track_offsets [last_track + 1];
+					track_offsets [last_track + 1] = 0;
+				} finally {
+					Marshal.FreeHGlobal (t.data);
+				}
+			} finally {
+				close (fd);
+			}
+			
+			Init ();
+		}
+	}
+}
