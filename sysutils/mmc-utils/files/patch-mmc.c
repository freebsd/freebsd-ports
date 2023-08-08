--- mmc.c.orig	2023-02-09 14:16:51 UTC
+++ mmc.c
@@ -234,6 +234,7 @@ static struct Command commands[] = {
 		"Run Field Firmware Update with <image name> on <device>.\n",
 	  NULL
 	},
+#if defined(__linux__)
 	{ do_erase, -4,
 	"erase", "<type> " "<start address> " "<end address> " "<device>\n"
 		"Send Erase CMD38 with specific argument to the <device>\n\n"
@@ -242,6 +243,7 @@ static struct Command commands[] = {
 		"secure-trim1 | secure-trim2 | trim \n",
 	NULL
 	},
+#endif
 	{ do_general_cmd_read, -1,
 	"gen_cmd read", "<device> [arg]\n"
 		"Send GEN_CMD (CMD56) to read vendor-specific format/meaning data from <device>\n\n"
@@ -260,6 +262,7 @@ static struct Command commands[] = {
 	  "Issues a CMD0 GO_PRE_IDLE",
 	  NULL
 	},
+#if defined(__linux__)
 	{ do_alt_boot_op, -1,
 	  "boot_operation", "<boot_data_file> <device>\n"
 	  "Does the alternative boot operation and writes the specified starting blocks of boot data into the requested file.\n\n"
@@ -272,6 +275,7 @@ static struct Command commands[] = {
 	  "4. The MMC will perform a soft reset, if your system cannot handle that do not use the boot operation from mmc-utils.\n",
 	  NULL
 	},
+#endif
 	{ 0, 0, 0, 0 }
 };
 
