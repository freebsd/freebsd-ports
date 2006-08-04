--- vidix/drivers/mga_vid.c.orig	Sun Jun 11 20:35:43 2006
+++ vidix/drivers/mga_vid.c	Mon Jul 31 22:48:55 2006
@@ -43,7 +43,7 @@
 
 #define MGA_VSYNC_POS 2
 
-#undef MGA_PCICONFIG_MEMDETECT
+#define MGA_PCICONFIG_MEMDETECT
 
 #define MGA_DEFAULT_FRAMES 4
 
@@ -1218,8 +1218,7 @@
 	    {
 		if ((lst[i].command & PCI_COMMAND_IO) == 0)
 		{
-			printf("[mga] Device is disabled, ignoring\n");
-			continue;
+			printf("[mga] Device is disabled, trying anyways.\n");
 		}
 		switch(lst[i].device)
 		{
