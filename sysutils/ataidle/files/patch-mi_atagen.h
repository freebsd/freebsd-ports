
$FreeBSD$

--- mi/atagen.h
+++ mi/atagen.h
@@ -62,6 +62,9 @@
 #define ATA_SMART_SUPPORTED	0x0001
 #define ATA_SMART_ENABLED	0x0001
 
+#define ATA_WC_SUPPORTED	0x0020
+#define ATA_WC_ENABLED		0x0020
+
 #define ATA__SETFEATURES	0xEF
 #define ATA__IDENTIFY		0xEC
 #define ATA__ATAPI_IDENTIFY	0xA1
@@ -76,6 +79,8 @@
 #define ATA_AUTOACOUSTIC_DISABLE	0xC2
 #define ATA_APM_ENABLE			0x05
 #define ATA_APM_DISABLE			0x85
+#define ATA_WC_ENABLE			0x02
+#define ATA_WC_DISABLE			0x82
 #define ATA_AUTOACOUSTIC_MAXPERF 	0xFE
 #define ATA_AUTOACOUSTIC_MINPERF 	0x80
 #define ATA_APM_MINPOWER_NO_STANDBY	0x80
@@ -156,6 +161,7 @@
 ATA*	ata_open(const char *device);
 void	ata_close(ATA *ata);
 int	ata_setidletimer(ATA *ata, uint32_t idle_mins);
+int	ata_setwc(ATA *ata, int enable);
 int	ata_sleep(ATA *ata);
 int	ata_setstandbytimer(ATA *ata, uint32_t standby_mins);
 int	ata_setacoustic(ATA *ata, uint32_t acoustic_val);
