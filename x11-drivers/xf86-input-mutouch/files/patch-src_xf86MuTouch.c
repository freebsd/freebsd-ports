# Finish converting AddEnabledDevice to xf86AddEnabledDevice
# Finish converting use of Error to ErrorF
# Correct a couple strings that should be const
#
--- src/xf86MuTouch.c.orig	2011-06-28 01:31:38 UTC
+++ src/xf86MuTouch.c
@@ -267,7 +267,7 @@ xf86MuTReadInput(InputInfoPtr	pInfo)
 			   (char *) (priv->rec_buf + priv->num_old_bytes),
 			   MuT_BUFFER_SIZE - priv->num_old_bytes));
   if (num_bytes < 0) {
-    Error("System error while reading from MuTouch touchscreen.");
+    ErrorF("System error while reading from MuTouch touchscreen.\n");
     return;
   }
 
@@ -483,7 +483,7 @@ xf86MuTGetReply(unsigned char	*buffer,
    * Okay, give up.
    */
   if (num_bytes < 0) {
-    Error("System error while reading from MuTouch touchscreen.");
+    ErrorF("System error while reading from MuTouch touchscreen.\n");
     return !Success;
   }
   DBG(4, ErrorF("Read %d bytes of reply\n", num_bytes));
@@ -789,7 +789,7 @@ xf86MuTControl(DeviceIntPtr	dev,
 	DBG(2, ErrorF("MuTouch touchscreen opening : %s\n", priv->input_dev));
 	pInfo->fd = xf86OpenSerial(pInfo->options);
 	if (pInfo->fd < 0) {
-	  Error("Unable to open MuTouch touchscreen device");
+	  ErrorF("Unable to open MuTouch touchscreen device\n");
 	  return !Success;
 	}
 	memset(req, 0, MuT_PACKET_SIZE);
@@ -845,7 +845,7 @@ xf86MuTControl(DeviceIntPtr	dev,
 	  goto not_success;
 	}
 	/*	goto not_success;*/
-	AddEnabledDevice(pInfo->fd);
+	xf86AddEnabledDevice(pInfo);
       }
 
       /*
@@ -1052,7 +1052,7 @@ xf86MuTUninit(InputDriverPtr	drv,
   xf86DeleteInput(pInfo, 0);
 }
 
-static char *default_options[] = {
+static const char *default_options[] = {
   "BaudRate", "9600",
   "StopBits", "1",
   "DataBits", "8",
@@ -1070,7 +1070,7 @@ xf86MuTInit(InputDriverPtr	drv,
 {
   InputInfoPtr		current;
   MuTPrivatePtr		priv=NULL;
-  char			*str;
+  const char		*str;
   int			portrait=0;
   int			rc = Success;
 
