--- gnome-cups-add/printerconf.c.orig	Fri Mar  7 14:48:48 2003
+++ gnome-cups-add/printerconf.c	Tue Jul 15 11:20:00 2003
@@ -12,7 +12,7 @@
 #include "snmpinter.h"
 
 #define IOCNR_GET_DEVICE_ID	1
-#define LPIOC_GET_DEVICE_ID(len) _IOC(_IOC_READ, 'P', IOCNR_GET_DEVICE_ID, len)	/* get device_id string */
+#define LPIOC_GET_DEVICE_ID(len) _IOC(IOC_OUT, 'P', IOCNR_GET_DEVICE_ID, len)	/* get device_id string */
 
 /*----------------------------------------------------------------
   libprinterconf - a function library for detecting and setting up
