Index: src/disk.c
diff -u src/disk.c.orig src/disk.c
--- src/disk.c.orig	Mon Jul  1 11:19:47 2002
+++ src/disk.c	Thu Feb 20 19:42:04 2003
@@ -70,7 +70,11 @@
 
 #if defined(__FreeBSD__)
 #include <osreldate.h>
+#if __FreeBSD_version >= 500101
+#include <sys/resource.h>
+#else
 #include <sys/dkstat.h>
+#endif
 #if __FreeBSD_version >= 300000
 #include <devstat.h>
 static struct statinfo	statinfo_cur;
