--- cef/tools/make_api_versions_header.py.orig	2026-09-06 17:31:54 UTC
+++ cef/tools/make_api_versions_header.py
@@ -34,7 +34,7 @@ def make_api_versions_header(json):
 #define CEF_API_HASH_{version} "$WINDOWS$"
 #elif defined(OS_MAC)
 #define CEF_API_HASH_{version} "$MAC$"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #define CEF_API_HASH_{version} "$LINUX$"
 #endif
 """
