--- services/virus_scan/clamav_mod.c.orig	2019-11-25 19:36:11 UTC
+++ services/virus_scan/clamav_mod.c
@@ -104,8 +104,8 @@ extern ci_off_t CLAMAV_MAXFILESIZE;
 extern ci_off_t CLAMAV_MAXSCANSIZE;
 extern char *CLAMAV_TMP;
 
-#define CLAMAV_VERSION_SIZE 64
-static char CLAMAV_VERSION[CLAMAV_VERSION_SIZE];
+#define _CLAMAV_VERSION_SIZE 64
+static char _CLAMAV_VERSION[_CLAMAV_VERSION_SIZE];
 #define CLAMAV_SIGNATURE_SIZE SERVICE_ISTAG_SIZE + 1
 static char CLAMAV_SIGNATURE[CLAMAV_SIGNATURE_SIZE];
 
@@ -641,13 +641,13 @@ void clamav_set_versions()
     CLAMAV_SIGNATURE[CLAMAV_SIGNATURE_SIZE - 1] = '\0';
 
      /*set the clamav version*/
-     snprintf(CLAMAV_VERSION, CLAMAV_VERSION_SIZE - 1, "%s/%d", str_version, version);
-     CLAMAV_VERSION[CLAMAV_VERSION_SIZE - 1] = '\0';
+     snprintf(_CLAMAV_VERSION, _CLAMAV_VERSION_SIZE - 1, "%s/%d", str_version, version);
+     _CLAMAV_VERSION[_CLAMAV_VERSION_SIZE - 1] = '\0';
 }
 
 const char *clamav_version()
 {
-    return CLAMAV_VERSION;
+    return _CLAMAV_VERSION;
 }
 
 const char *clamav_signature()
