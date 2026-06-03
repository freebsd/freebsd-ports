-- Guard hasOriginalSignalHandler() and handle_signal() with #ifdef __linux__ so they
-- are not defined on non-Linux platforms where they are never called; the previous code
-- defined them unconditionally, causing -Wunused-function errors on FreeBSD with Clang.
--- third_party/kineto/libkineto/src/ConfigLoader.cpp.orig	2026-05-16 03:52:38 UTC
+++ third_party/kineto/libkineto/src/ConfigLoader.cpp
@@ -46,17 +46,13 @@ static struct sigaction originalUsr2Handler = {};
 // Look for an on-demand config file.
 // If none is found, default to base config.
 // Try to not affect existing handlers
-static bool hasOriginalSignalHandler() {
 #ifdef __linux__
+static bool hasOriginalSignalHandler() {
   return originalUsr2Handler.sa_handler != nullptr ||
       originalUsr2Handler.sa_sigaction != nullptr;
-#else
-  return false;
-#endif
 }
 
-static void handle_signal([[maybe_unused]] int signal) {
-#ifdef __linux__
+static void handle_signal(int signal) {
   if (signal == SIGUSR2) {
     ConfigLoader::instance().handleOnDemandSignal();
     if (hasOriginalSignalHandler()) {
@@ -67,8 +63,8 @@ static void handle_signal([[maybe_unused]] int signal)
       sigaction(SIGUSR2, &act, &originalUsr2Handler);
     }
   }
-#endif
 }
+#endif
 
 static void setupSignalHandler([[maybe_unused]] bool enableSigUsr2) {
 #ifdef __linux__
