Index: src/cpu.c
diff -u src/cpu.c.orig src/cpu.c
--- src/cpu.c.orig	Mon Jul  1 11:19:18 2002
+++ src/cpu.c	Thu Feb 20 19:46:29 2003
@@ -141,8 +141,20 @@
 
 /* ----- FreeBSD ---------------------------------------------------- */
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#if __FreeBSD_version >= 500101
+#include <sys/resource.h>
+#else
+#include <sys/dkstat.h>
+#endif
+#endif
+
+#if defined(__OpenBSD__)
 #include <sys/dkstat.h>
+#endif
+
+#if defined(__FreeBSD__) || defined(__OpenBSD__)
 #include <kvm.h>
 
 static struct nlist nl[] = {
