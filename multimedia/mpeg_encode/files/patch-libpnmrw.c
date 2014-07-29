--- ./libpnmrw.c~	Thu Aug  1 08:52:14 1996
+++ ./libpnmrw.c	Thu Aug  1 08:51:26 1996
@@ -126,7 +126,9 @@
   pm_perror( reason )
 char* reason;
 {
+#ifndef __FreeBSD__
   extern char* sys_errlist[];
+#endif
   extern int errno;
   char* e;
