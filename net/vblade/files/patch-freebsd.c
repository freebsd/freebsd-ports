--- freebsd.c.orig	2015-01-28 07:26:22.000000000 +0600
+++ freebsd.c	2015-01-28 07:29:23.000000000 +0600
@@ -25,7 +25,7 @@
 #include <sys/types.h>
 #include <net/if.h>
 #include <sys/stat.h>
-#include <sys/disklabel.h>
+#include <sys/disk.h>
 #include <sys/select.h>
 #include <sys/sysctl.h>
 
@@ -267,14 +267,14 @@
 vlong
 getsize(int fd)
 {
+	off_t media_size;
 	vlong size;
 	struct stat s;
 	int n;
-	struct disklabel lab;
 
 	// Try getting disklabel from block dev
-	if ((n = ioctl(fd, DIOCGDINFO, lab)) != -1) {  
-		size = lab.d_secsize * lab.d_secperunit;
+	if ((n = ioctl(fd, DIOCGMEDIASIZE, &media_size)) != -1) {  
+		size = media_size;
 	} else {
 		// must not be a block special dev
 		if (fstat(fd, &s) == -1) {
