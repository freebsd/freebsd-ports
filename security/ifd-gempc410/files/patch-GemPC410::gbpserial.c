--- GemPC410/gbpserial.c.orig	Tue May 13 16:49:38 2003
+++ GemPC410/gbpserial.c	Tue May 13 16:53:04 2003
@@ -410,7 +410,7 @@
 		return STATUS_UNSUCCESSFUL;
 	}
 
-	sprintf(dev_name, "/dev/pcsc/%d", (int) channel);
+	sprintf(dev_name, "/dev/cuaa%d", (int) channel);
 
 	/* check if the same channel is not already used */
 	for (i=0; i<PCSCLITE_MAX_CHANNELS; i++)
