--- tools/gn/args.cc.orig	2017-04-19 19:06:54 UTC
+++ tools/gn/args.cc
@@ -298,6 +298,8 @@ void Args::SetSystemVarsLocked(Scope* de
   os = "mac";
 #elif defined(OS_LINUX)
   os = "linux";
+#elif defined(OS_BSD)
+  os = "bsd";
 #elif defined(OS_ANDROID)
   os = "android";
 #elif defined(OS_NETBSD)
