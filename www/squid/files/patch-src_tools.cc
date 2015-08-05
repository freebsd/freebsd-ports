--- src/tools.cc.orig	2015-08-01 06:08:17 UTC
+++ src/tools.cc
@@ -635,7 +635,7 @@ no_suid(void)
     uid = geteuid();
     debugs(21, 3, "no_suid: PID " << getpid() << " giving up root priveleges forever");
 
-    if (setuid(0) < 0)
+    if (setuid(0) < 0 && TheProcessKind != pkHelper)
         debugs(50, DBG_IMPORTANT, "WARNING: no_suid: setuid(0): " << xstrerror());
 
     if (setuid(uid) < 0)
