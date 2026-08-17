--- libvpl/src/mfx_dispatcher_vpl_lowlatency.cpp.orig	2025-12-17 23:04:39 UTC
+++ libvpl/src/mfx_dispatcher_vpl_lowlatency.cpp
@@ -18,7 +18,7 @@
         #define LIB_ONEVPL L"libmfx64-gen.dll"
         #define LIB_MSDK   L"libmfxhw64.dll"
     #endif
-#elif defined(__linux__)
+#elif defined(__unix__)
     // Linux x64
     #define LIB_ONEVPL "libmfx-gen.so.1.2"
     #define LIB_MSDK   "libmfxhw64.so.1"
@@ -191,14 +191,17 @@ mfxStatus LoaderCtxVPL::LoadLibsFromMultipleDirs(LibTy
 }
 
 mfxStatus LoaderCtxVPL::LoadLibsFromMultipleDirs(LibType libType) {
-#ifdef __linux__
+#ifdef __unix__
     // clang-format off
 
     // standard paths for RT installation on Linux
     std::vector<std::string> llSearchDir = {
+#ifdef __linux__
         "/usr/lib/x86_64-linux-gnu",
+#endif
         "/lib",
         "/usr/lib",
+        "%%PREFIX%%/lib",
         "/lib64",
         "/usr/lib64",
     };
