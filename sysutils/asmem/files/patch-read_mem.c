--- read_mem.c.dist	Fri Sep 19 01:06:01 2003
+++ read_mem.c	Tue Nov 30 18:52:06 2004
@@ -56,6 +56,7 @@
 // Machine dependent headers
 // FreeBSD
 #if defined(__FreeBSD__)
+#include <sys/param.h>
 #include <sys/conf.h>
 #include <osreldate.h>
 #include <kvm.h>
