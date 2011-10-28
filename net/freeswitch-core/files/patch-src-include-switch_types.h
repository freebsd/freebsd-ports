--- src/include/switch_types.h.orig	2011-02-02 16:27:41.000000000 -0500
+++ src/include/switch_types.h	2011-02-02 16:29:16.000000000 -0500
@@ -108,7 +108,7 @@
 #define SWITCH_DEFAULT_DTMF_DURATION 2000
 #define SWITCH_MIN_DTMF_DURATION 400
 #define SWITCH_MAX_DTMF_DURATION 192000
-#define SWITCH_DEFAULT_DIR_PERMS SWITCH_FPROT_UREAD | SWITCH_FPROT_UWRITE | SWITCH_FPROT_UEXECUTE | SWITCH_FPROT_GREAD | SWITCH_FPROT_GEXECUTE
+#define SWITCH_DEFAULT_DIR_PERMS SWITCH_FPROT_UREAD | SWITCH_FPROT_UWRITE | SWITCH_FPROT_UEXECUTE | SWITCH_FPROT_GREAD | SWITCH_FPROT_GWRITE | SWITCH_FPROT_GEXECUTE
 #ifdef WIN32
 #define SWITCH_PATH_SEPARATOR "\\"
 #else
@@ -409,6 +409,7 @@
 	char *storage_dir;
 	char *recordings_dir;
 	char *sounds_dir;
+	char *voicemail_dir;
 };
 
 typedef struct switch_directories switch_directories;
