--- src/cfg.h.orig	2026-08-26 23:50:52 UTC
+++ src/cfg.h
@@ -394,7 +394,7 @@ extern config_t cfg;   // Holds config parameters
 
 extern char *cfg_path; // Path to config file
 extern config_t cfg;   // Holds config parameters
-#if !defined(__APPLE__) && !defined(WIN32)
+#if !defined(__APPLE__) && !defined(WIN32) && defined(HAVE_JACK)
 extern char *jack_client_name; // JACK client name
 #endif
 
