--- gst/fsrtpconference/fs-rtp-session.c.orig	2009-02-27 23:45:45.000000000 -0500
+++ gst/fsrtpconference/fs-rtp-session.c	2009-02-27 23:46:16.000000000 -0500
@@ -3613,10 +3613,10 @@ fs_rtp_session_associate_free_substreams
     }
     else
     {
-      GST_ERROR ("Could not associate a substream with its stream",
+      GST_ERROR ("Could not associate a substream with its stream (%s)",
           error->message);
       fs_session_emit_error (FS_SESSION (session), error->code,
-          "Could not associate a substream with its stream",
+          "Could not associate a substream with its stream (%s)",
           error->message);
     }
     g_clear_error (&error);
