--- include/ipmitool/ipmi_hpmfwupg.h.orig	2016-06-29 18:01:49 UTC
+++ include/ipmitool/ipmi_hpmfwupg.h
@@ -800,7 +800,7 @@ typedef struct _VERSIONINFO {
 	char descString[HPMFWUPG_DESC_STRING_LENGTH + 1];
 }VERSIONINFO, *PVERSIONINFO;
 
-VERSIONINFO gVersionInfo[HPMFWUPG_COMPONENT_ID_MAX];
+extern VERSIONINFO gVersionInfo[HPMFWUPG_COMPONENT_ID_MAX];
 
 #define TARGET_VER (0x01)
 #define ROLLBACK_VER (0x02)
