--- src/tools.cc.orig	2014-08-19 13:38:40.000000000 +0400
+++ src/tools.cc	2014-08-19 13:39:00.000000000 +0400
@@ -735,7 +735,7 @@
     uid = geteuid();
     debugs(21, 3, "no_suid: PID " << getpid() << " giving up root priveleges forever");
 
-    if (setuid(0) < 0)
+    if (setuid(0) < 0 && TheProcessKind != pkHelper)
         debugs(50, DBG_IMPORTANT, "WARNING: no_suid: setuid(0): " << xstrerror());
 
     if (setuid(uid) < 0)
