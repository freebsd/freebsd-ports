--- libclamav/c++/llvm/lib/System/Unix/Signals.inc
+++ libclamav/c++/llvm/lib/System/Unix/Signals.inc
@@ -191,7 +191,8 @@ static void PrintStackTrace(void *) {
   // Use backtrace() to output a backtrace on Linux systems with glibc.
   int depth = backtrace(StackTrace,
                         static_cast<int>(array_lengthof(StackTrace)));
-#if HAVE_DLFCN_H && __GNUG__
+#if HAVE_DLFCN_H && __GNUG__ && 0
+/* CLAMAV LOCAL: turn off dladdr() because we don't link -ldl */
   int width = 0;
   for (int i = 0; i < depth; ++i) {
     Dl_info dlinfo;
