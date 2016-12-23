--- src/tools.cc.orig	2016-12-16 10:06:20 UTC
+++ src/tools.cc
@@ -603,7 +603,7 @@ no_suid(void)
     uid = geteuid();
     debugs(21, 3, "no_suid: PID " << getpid() << " giving up root priveleges forever");
 
-    if (setuid(0) < 0) {
+    if (setuid(0) < 0 && TheProcessKind != pkHelper) {
         int xerrno = errno;
         debugs(50, DBG_IMPORTANT, "WARNING: no_suid: setuid(0): " << xstrerr(xerrno));
     }
