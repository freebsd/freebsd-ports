--- tools/gn/args.cc.orig	2017-03-09 20:04:48 UTC
+++ tools/gn/args.cc
@@ -270,6 +270,8 @@ void Args::SetSystemVarsLocked(Scope* de
   os = "mac";
 #elif defined(OS_LINUX)
   os = "linux";
+#elif defined(OS_BSD)
+  os = "bsd";
 #elif defined(OS_ANDROID)
   os = "android";
 #elif defined(OS_NETBSD)
