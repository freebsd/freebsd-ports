--- libvpl/src/mfx_dispatcher_vpl.h.orig	2025-04-18 15:44:33 UTC
+++ libvpl/src/mfx_dispatcher_vpl.h
@@ -48,7 +48,7 @@ typedef char CHAR_TYPE;
         #define MSDK_LIB_NAME L"libmfxhw64."
     #endif
     #define ONEVPL_PRIORITY_PATH_VAR L"ONEVPL_PRIORITY_PATH"
-#elif defined(__linux__)
+#elif defined(__unix__)
     // Linux x64
     #define MSDK_LIB_NAME            "libmfxhw64."
     #define ONEVPL_PRIORITY_PATH_VAR "ONEVPL_PRIORITY_PATH"
