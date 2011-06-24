
$FreeBSD$

--- mi/util.c
+++ mi/util.c
@@ -230,19 +230,19 @@
 	printf("Model:\t\t\t%s\n", model);
 	printf("Serial:\t\t\t%s\n", serial);
 	printf("Firmware Rev:\t\t%s\n", firmware);
-	ata_version = ata_getversionstring(buf[80]);
+	ata_version = ata_getversionstring(ident.version_major);
 	printf("ATA revision:\t\t%s\n", (ident.version_major > 1)?
 			ata_version : "unknown/pre ATA-2");
-	printf("LBA 48:\t\t\t%s\n", (buf[86] & 0x400)? "yes" : "no");
+	printf("LBA 48:\t\t\t%s\n", (ident.cmd_enabled2 & 0x400)? "yes" : "no");
 	printf("Geometry:\t\t%d cyls, %d heads, %d spt\n",
-			buf[1], buf[3], buf[6]);
+			ident.word1, ident.word3, ident.word6);
 
 	if (ata_version != NULL)
 		free(ata_version);
 
 	mbsize = 0;
 
-	if (buf[86] & 0x400)
+	if (ident.cmd_enabled2 & 0x400)
 	{
 		mbsize = (((uint64_t)ident.max_lba48_address[0] +
 			((uint64_t)ident.max_lba48_address[1] << 16) +
@@ -254,12 +254,14 @@
 		mbsize = ((ident.nsect[0] + (ident.nsect[1] << 16))*512)/1048576;
 	}
 
-	bool smart_supported = buf[82] & ATA_SMART_SUPPORTED;
-	bool smart_enabled   = buf[85] & ATA_SMART_ENABLED;
-	bool apm_supported   = buf[83] & ATA_APM_SUPPORTED;
-	bool apm_enabled     = buf[86] & ATA_APM_ENABLED;
-	bool aam_supported   = buf[83] & ATA_AAM_SUPPORTED;
-	bool aam_enabled     = buf[86] & ATA_AAM_ENABLED;
+	bool smart_supported = ident.cmd_supp1 & ATA_SMART_SUPPORTED;
+	bool smart_enabled   = ident.cmd_enabled1 & ATA_SMART_ENABLED;
+        bool wc_supported    = ident.cmd_supp1 & ATA_WC_SUPPORTED;
+        bool wc_enabled      = ident.cmd_enabled1 & ATA_WC_ENABLED;
+	bool apm_supported   = ident.cmd_supp2 & ATA_APM_SUPPORTED;
+	bool apm_enabled     = ident.cmd_enabled2 & ATA_APM_ENABLED;
+	bool aam_supported   = ident.cmd_supp2 & ATA_AAM_SUPPORTED;
+	bool aam_enabled     = ident.cmd_enabled2 & ATA_AAM_ENABLED;
 
 	printf("Capacity:\t\t%u%s\n", (mbsize < 1024)?
 			mbsize : mbsize/1024, (mbsize < 1024)? "MB" : "GB");
@@ -269,12 +271,17 @@
 	if (smart_supported)
 		printf("SMART Enabled: \t\t%s\n", smart_enabled? "yes" : "no" );
 
+        printf("Write Cache Supported: \t%s\n", wc_supported? "yes" : "no" );
+
+        if (wc_supported)
+                printf("Write Cache Enabled: \t\t%s\n", wc_enabled? "yes" : "no" );
+
 	printf("APM Supported: \t\t%s\n", apm_supported? "yes" : "no" );
 
 	if (apm_supported) {
 		printf("APM Enabled: \t\t%s\n", apm_enabled? "yes" : "no" );
 		if (apm_enabled)
-			printf("APM Value: \t\t%d\n", buf[91]);
+			printf("APM Value: \t\t%d\n", ident.apm_value);
 	}
 
 	printf("AAM Supported: \t\t%s\n", aam_supported? "yes" : "no" );
@@ -282,9 +289,9 @@
 	if (aam_supported) {
 		printf("AAM Enabled: \t\t%s\n", aam_enabled? "yes" : "no");
 		if (aam_enabled)
-			printf("AAM Value: \t\t%d\n", ((buf[94] & 0x00FF))-127);
+			printf("AAM Value: \t\t%d\n", ((ident.aam_value & 0x00FF))-127);
 
-		printf("Vendor Recommended AAM: %d\n", ((buf[94] & 0xFF00) >> 8)-127);
+		printf("Vendor Recommended AAM: %d\n", ((ident.aam_value & 0xFF00) >> 8)-127);
 	}
 }
 
@@ -345,6 +352,20 @@
 	return rc;
 }
 
+int
+ata_setwc(ATA *ata, int enable)
+{
+	int rc, cmd;
+
+	/* allocate and initialize the ata_cmd structure */
+	ata_init(ata);
+	cmd = enable ? ATA_WC_ENABLE : ATA_WC_DISABLE;
+	rc = ata_cmd(ata, ATA__SETFEATURES, cmd, 0);
+	if(rc)
+		perror("Failed to configure Write Cache");
+	return rc;
+}
+
 /*
  * Sets the acoustic level on modern hard drives.   This is used to run it
  * at a lower speed/performance level, which in turn reduces noise.
