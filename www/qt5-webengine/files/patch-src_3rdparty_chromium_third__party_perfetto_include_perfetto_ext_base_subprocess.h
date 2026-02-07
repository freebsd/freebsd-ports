--- src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/subprocess.h.orig	2023-11-09 11:32:20 UTC
+++ src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/subprocess.h
@@ -173,7 +173,7 @@ class Subprocess {
   };
 
   explicit Subprocess(std::initializer_list<std::string> exec_cmd = {});
-  Subprocess(Subprocess&&);
+  Subprocess(Subprocess&&) noexcept;
   Subprocess& operator=(Subprocess&&);
   ~Subprocess();  // It will KillAndWaitForTermination() if still alive.
 
