--- vidix/drivers/mga_vid.c.orig	Thu Sep  2 13:34:25 2004
+++ vidix/drivers/mga_vid.c	Tue Apr 12 17:51:55 2005
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
