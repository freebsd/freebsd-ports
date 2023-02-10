--- src/3rdparty/chromium/components/crash/core/app/chrome_crashpad_handler.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/components/crash/core/app/chrome_crashpad_handler.cc
@@ -6,5 +6,9 @@ int main(int argc, char* argv[]) {
 extern "C" int CrashpadHandlerMain(int argc, char* argv[]);
 
 int main(int argc, char* argv[]) {
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
+  return -1;
+#else
   return CrashpadHandlerMain(argc, argv);
+#endif
 }
