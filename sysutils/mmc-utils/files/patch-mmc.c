--- mmc.c.orig	2021-12-18 19:59:21 UTC
+++ mmc.c
@@ -229,6 +229,7 @@ static struct Command commands[] = {
 		"Run Field Firmware Update with <image name> on <device>.\n",
 	  NULL
 	},
+#if defined(__linux__)
 	{ do_erase, -4,
 	"erase", "<type> " "<start address> " "<end address> " "<device>\n"
 		"Send Erase CMD38 with specific argument to the <device>\n\n"
@@ -237,6 +238,7 @@ static struct Command commands[] = {
 		"secure-trim1 | secure-trim2 | trim \n",
 	NULL
 	},
+#endif
 	{ 0, 0, 0, 0 }
 };
 
