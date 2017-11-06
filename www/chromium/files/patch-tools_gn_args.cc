--- tools/gn/args.cc.orig	2017-06-05 19:03:29 UTC
+++ tools/gn/args.cc
@@ -298,6 +298,8 @@ void Args::SetSystemVarsLocked(Scope* dest) const {
   os = "mac";
 #elif defined(OS_LINUX)
   os = "linux";
+#elif defined(OS_BSD)
+  os = "bsd";
 #elif defined(OS_ANDROID)
   os = "android";
 #elif defined(OS_NETBSD)
