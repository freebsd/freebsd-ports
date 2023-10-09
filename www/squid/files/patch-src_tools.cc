--- src/tools.cc.orig	2023-02-28 09:10:25 UTC
+++ src/tools.cc
@@ -650,7 +650,7 @@ no_suid(void)
     uid = geteuid();
     debugs(21, 3, "no_suid: PID " << getpid() << " giving up root privileges forever");
 
-    if (setuid(0) < 0) {
+    if (setuid(0) < 0 && TheProcessKind != pkHelper) {
         int xerrno = errno;
         debugs(50, DBG_IMPORTANT, "WARNING: no_suid: setuid(0): " << xstrerr(xerrno));
     }
