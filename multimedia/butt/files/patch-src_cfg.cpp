--- src/cfg.cpp.orig	2026-08-26 23:50:43 UTC
+++ src/cfg.cpp
@@ -39,7 +39,7 @@ char *cfg_path;
 
 config_t cfg;
 char *cfg_path;
-#if !defined(__APPLE__) && !defined(WIN32)
+#if !defined(__APPLE__) && !defined(WIN32) && defined(HAVE_JACK)
 char *jack_client_name;
 #endif
 
