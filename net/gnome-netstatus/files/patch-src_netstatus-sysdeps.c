--- src/netstatus-sysdeps.c.orig	Wed Mar 24 14:23:47 2004
+++ src/netstatus-sysdeps.c	Wed Mar 24 14:25:19 2004
@@ -331,7 +331,6 @@
 
     error_shutdown:
       g_io_channel_unref (channel);
-      g_io_channel_shutdown (channel, TRUE, NULL);
       close (pipe_out);
     }
   else
