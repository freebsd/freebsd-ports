--- ./libntfs/device.c.orig	Tue Jan  9 18:22:57 2007
+++ ./libntfs/device.c	Mon Apr 30 13:40:54 2007
@@ -63,6 +63,9 @@
 #ifdef HAVE_LINUX_HDREG_H
 #include <linux/hdreg.h>
 #endif
+#ifdef __FreeBSD__
+#include <sys/disk.h>
+#endif
 
 #include "types.h"
 #include "mst.h"
@@ -533,6 +536,17 @@
 		}
 	}
 #endif
+#ifdef DIOCGMEDIASIZE 
+	{       off_t size;
+
+		if (dev->d_ops->ioctl(dev, DIOCGMEDIASIZE, &size) >= 0) {
+			ntfs_log_debug("DIOCGMEDIASIZE nr bytes = %llu (0x%llx)\n",
+					(unsigned long long)size,
+					(unsigned long long)size);
+			return (s64)size / block_size;
+		}
+	}
+#endif
 	/*
 	 * We couldn't figure it out by using a specialized ioctl,
 	 * so do binary search to find the size of the device.
@@ -681,7 +695,24 @@
 			return sect_size;
 		}
 	}
-#else
+#elif defined(DIOCGSECTORSIZE)
+	/*
+	 * XXX On FreeBSD (where we have DIOCGSECTORSIZE) the low-level I/O
+	 * system already knows the sector size, and doing an ioctl is needless.
+	 * However, I don't know how to extract that information cleanly,
+	 * without letting a bunch of platform specific #ifdef-s to sneak in.
+	 * So now I rather just re-do the ioctl...
+	 */
+	{
+		size_t sect_size = 0;
+
+		if (!dev->d_ops->ioctl(dev, DIOCGSECTORSIZE, &sect_size)) {
+			ntfs_log_debug("DIOCGSECTORSIZE sector size = %d bytes\n",
+				(int)sect_size);
+			return sect_size;
+		}
+	}
+#else
 	errno = EOPNOTSUPP;
 #endif
 	return -1;
