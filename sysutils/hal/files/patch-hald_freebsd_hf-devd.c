--- hald/freebsd/hf-devd.c.orig	2011-01-08 12:59:30.000000000 -0500
+++ hald/freebsd/hf-devd.c	2011-01-08 13:04:46.000000000 -0500
@@ -398,7 +398,7 @@ hf_devd_event_cb (GIOChannel *source, GI
       hf_devd_process_event(event);
       g_free(event);
     }
-  else if (status == G_IO_STATUS_AGAIN)
+  else if (status == G_IO_STATUS_AGAIN || status == G_IO_STATUS_EOF)
     {
       hf_devd_init();
       if (hf_devd_inited)
