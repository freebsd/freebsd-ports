--- src/3rdparty/gn/tools/gn/args.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/gn/tools/gn/args.cc
@@ -294,6 +294,8 @@ void Args::SetSystemVarsLocked(Scope* dest) const {
   os = "mac";
 #elif defined(OS_LINUX)
   os = "linux";
+#elif defined(OS_BSD)
+  os = "bsd";
 #elif defined(OS_AIX)
   os = "aix";
 #else
