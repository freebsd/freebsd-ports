--- src/ck-session.c.orig	2025-03-20 16:35:45 UTC
+++ src/ck-session.c
@@ -815,7 +815,7 @@ ck_session_resume_all_devices (CkSession *session)
                         continue;
                 }
 
-                message = g_dbus_message_new_signal (session->priv->id,
+                message = g_dbus_message_new_signal (session->priv->path,
                                                      DBUS_SESSION_INTERFACE,
                                                      "ResumeDevice");
 
