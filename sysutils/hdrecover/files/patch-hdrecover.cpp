--- hdrecover.cpp.orig	2013-07-27 04:37:04.000000000 -0700
+++ hdrecover.cpp	2013-07-28 08:04:06.970389678 -0700
@@ -26,12 +26,20 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <unistd.h>
+#ifdef __FreeBSD_cc_version
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 #include <errno.h>
 #include <string.h>
 #include <time.h>
 #include <sys/ioctl.h>
+#ifdef __FreeBSD_cc_version
+static int secsize = 0;		/* the sensed sector size */
+#else
 #include <linux/fs.h>
+#endif
 
 int badblocks = 0;
 int recovered = 0;
@@ -47,6 +55,34 @@
 
 unsigned long long length = 0;
 
+#ifdef __FreeBSD_cc_version
+static ssize_t
+get_sec_size()
+{
+
+#define MAX_SEC_SIZE 2048       /* maximum section size that is supported */
+#define MIN_SEC_SIZE 512        /* the sector size to start sensing at */
+
+	char buf[MAX_SEC_SIZE];
+
+	lseek(fd, (0), 0);
+	if (secsize == 0)
+		for (secsize = MIN_SEC_SIZE; secsize <= MAX_SEC_SIZE;
+		     secsize *= 2) {
+			/* try the read */
+			int size = read(fd, buf, secsize);
+			if (size == secsize)
+				/* it worked so return */
+				return secsize;
+		}
+	else
+		return read(fd, buf, secsize);
+  
+	/* we failed to read at any of the sizes */
+	return -1;
+}
+#endif
+
 int correctsector(unsigned long long sectornum)
 {
     int ret = 0;
@@ -178,7 +214,11 @@
 	return 1;
     }
 
+#ifdef __FreeBSD_cc_version
+    if ((phys_block_size = get_sec_size()) == -1) {
+#else
     if (ioctl(fd, BLKPBSZGET, &phys_block_size) == -1) {
+#endif
         printf("Failed to get physical block size of device\n");
         return 1;
     }
@@ -268,7 +308,7 @@
 		sprintf(p, "%d seconds", remaining);
 	    }
 	    printf("Sector %Ld (%02d%%) ETR: %s\n",
-		   sectornum, (int) ((sectornum * 100) / length), rs);
+		   (long) sectornum, (long int) ((sectornum * 100) / length), rs);
 	}
     }
 
