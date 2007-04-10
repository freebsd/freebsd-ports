--- src/mpegmuxer.cpp~	Fri Dec 16 20:14:03 2005
+++ src/mpegmuxer.cpp	Mon Apr  9 16:55:43 2007
@@ -25,6 +25,10 @@
 #include <assert.h>
 #include "mpegmuxer.h"
 
+#ifndef O_BINARY
+#define O_BINARY    0
+#endif /* O_BINARY */
+
 /// video bitrate in bit/s
 #define VIDEOBITRATE (9500000)
 /// vbv buffer size in units of 1024 bytes
@@ -126,7 +130,7 @@
   allbuffers*=1.05; // 5% assumed muxing overhead
   ptsoffset=pts_t(90000.*(allbuffers/50./muxrate))+90;
 
-  fd=::open(filename,O_WRONLY|O_CREAT|O_TRUNC,0666);
+  fd=::open(filename,O_WRONLY|O_CREAT|O_TRUNC|O_BINARY,0666);
   }
 
 mpegmuxer::~mpegmuxer()
@@ -149,6 +153,11 @@
   stream * const s=st[str];
   if (!s)
     return false;
+  if (len == 0) {
+	// I'm not sure why this happens, but it does. --mr
+	fprintf(stderr, "mpegmuxer::putpacket called with zero length, str=%d\n", str);
+	return false;
+  }
   pts+=ptsoffset;
   dts+=ptsoffset;
   au *newau=new au(data,len,pts,dts,flags);
@@ -173,8 +182,8 @@
             } else if (d[3]==0xb3) // sequence header
             {
             d[8]=(VIDEOBITRATE/400) >> 10;
-            d[9]=(VIDEOBITRATE/400) >> 2;
-            d[10]=((VIDEOBITRATE/400) << 6)|0x20|(((VBVBUFFERSIZE/2)>>5)&0x1f);
+            d[9]=((VIDEOBITRATE/400) >> 2) & 0xff;
+            d[10]=(((VIDEOBITRATE/400) << 6)&0xc0)|0x20|(((VBVBUFFERSIZE/2)>>5)&0x1f);
             d[11]=(d[11]&0x07)|((VBVBUFFERSIZE/2)<<3);
             j+=12;
             } else if (d[3]==0xb5) // extension
@@ -473,6 +482,16 @@
     //       }
 
 
+    int pes_padding = 0;
+    if (packsize) {
+      int maxpayload = pack::maxpayload(packsize);
+      assert(len <= maxpayload);
+      if (maxpayload - len < 8)
+        pes_padding = maxpayload - len;
+      headerlen += pes_padding;
+      len += pes_padding;
+      }
+
     pack * const p=new pack(packsize,len,muxrate,a->getdts());
     s->packlist.push_back(p);
     ++s->packet;
@@ -541,6 +560,14 @@
         len-=3;
         headerext=false;
         headerlen-=3;
+        }
+      if (pes_padding > 0) {
+        memset(data, 0xff, pes_padding);
+        data += pes_padding;
+        headerlen -= pes_padding;
+        plen -= pes_padding;
+        len -= pes_padding;
+        pes_padding = 0;
         }
       if (isprivatestream) {
         *(data++)=s->id & 0xff;
