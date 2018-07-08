--- src/tools.cc.orig	2018-06-11 16:30:57 UTC
+++ src/tools.cc
@@ -605,7 +605,7 @@ no_suid(void)
     uid = geteuid();
     debugs(21, 3, "no_suid: PID " << getpid() << " giving up root privileges forever");
 
-    if (setuid(0) < 0) {
+    if (setuid(0) < 0 && TheProcessKind != pkHelper) {
         int xerrno = errno;
         debugs(50, DBG_IMPORTANT, "WARNING: no_suid: setuid(0): " << xstrerr(xerrno));
     }
