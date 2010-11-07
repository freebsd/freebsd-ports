--- src/include/tcsd.h.orig	2010-05-03 11:54:15.000000000 +0900
+++ src/include/tcsd.h	2010-10-24 22:28:52.708555289 +0900
@@ -50,14 +50,22 @@
 
 #define TCSD_CONFIG_FILE	ETC_PREFIX "/tcsd.conf"
 
+#ifndef TSS_USER_NAME
 #define TSS_USER_NAME		"tss"
+#endif
+#ifndef TSS_GROUP_NAME
 #define TSS_GROUP_NAME		"tss"
+#endif
+
+#ifndef TPM_PREFIX
+#define TPM_PREFIX "/lib/tpm"
+#endif
 
 #define TCSD_DEFAULT_MAX_THREADS	10
-#define TCSD_DEFAULT_SYSTEM_PS_FILE	VAR_PREFIX "/lib/tpm/system.data"
-#define TCSD_DEFAULT_SYSTEM_PS_DIR	VAR_PREFIX "/lib/tpm"
-#define TCSD_DEFAULT_FIRMWARE_LOG_FILE	"/sys/kernel/security/tpm0/binary_bios_measurements"
-#define TCSD_DEFAULT_KERNEL_LOG_FILE	"/sys/kernel/security/ima/binary_runtime_measurements"
+#define TCSD_DEFAULT_SYSTEM_PS_FILE	VAR_PREFIX TPM_PREFIX "/system.data"
+#define TCSD_DEFAULT_SYSTEM_PS_DIR	VAR_PREFIX TPM_PREFIX
+#define TCSD_DEFAULT_FIRMWARE_LOG_FILE	"/var/run/tpm/binary_bios_measurements"
+#define TCSD_DEFAULT_KERNEL_LOG_FILE	"/var/run/ima/binary_runtime_measurements"
 #define TCSD_DEFAULT_FIRMWARE_PCRS	0x00000000
 #define TCSD_DEFAULT_KERNEL_PCRS	0x00000000
 
