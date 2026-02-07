--- clients/lcdproc/iface.c.orig	2020-09-28 23:25:01.655900000 +0200
+++ clients/lcdproc/iface.c	2020-09-28 23:25:27.294816000 +0200
@@ -37,6 +37,7 @@
 static char unit_label[10] = "B";	/* default unit label is Bytes */
 static int transfer_screen = 0;	/* by default, transfer screen is not shown */
 
+IfaceInfo iface[MAX_INTERFACES]; /* interface info */
 
 /** Reads and parses configuration file.
  * \return  0 on success, -1 on error
