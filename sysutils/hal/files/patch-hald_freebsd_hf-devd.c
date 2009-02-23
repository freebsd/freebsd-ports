--- hald/freebsd/hf-devd.c.orig	2008-05-07 19:23:59.000000000 -0400
+++ hald/freebsd/hf-devd.c	2009-02-23 01:44:32.000000000 -0500
@@ -40,7 +40,11 @@
 #include "hf-acpi.h"
 #include "hf-net.h"
 #include "hf-pcmcia.h"
+#include "hf-storage.h"
 #include "hf-usb.h"
+#ifdef HAVE_LIBUSB20
+#include "hf-usb2.h"
+#endif
 #include "hf-util.h"
 
 #define HF_DEVD_SOCK_PATH		"/var/run/devd.pipe"
@@ -51,10 +55,14 @@
 #define HF_DEVD_EVENT_NOMATCH		'?'
 
 static HFDevdHandler *handlers[] = {
+#ifdef HAVE_LIBUSB20
+  &hf_usb2_devd_handler,
+#endif
   &hf_usb_devd_handler,
   &hf_net_devd_handler,
   &hf_acpi_devd_handler,
-  &hf_pcmcia_devd_handler
+  &hf_pcmcia_devd_handler,
+  &hf_storage_devd_handler
 };
 
 static gboolean hf_devd_inited = FALSE;
@@ -381,13 +389,13 @@ hf_devd_event_cb (GIOChannel *source, GI
 
   status = g_io_channel_read_line(source, &event, NULL, &terminator, NULL);
 
-  if (status != G_IO_STATUS_NORMAL)
+  if (status == G_IO_STATUS_NORMAL)
     {
       event[terminator] = 0;
       hf_devd_process_event(event);
       g_free(event);
     }
-  else if (status != G_IO_STATUS_AGAIN)
+  else if (status == G_IO_STATUS_AGAIN)
     {
       hf_devd_init();
       if (hf_devd_inited)
