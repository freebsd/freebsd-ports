--- ./midori/midori-session.c.orig	2013-02-05 23:28:05.000000000 +0000
+++ ./midori/midori-session.c	2013-02-07 06:47:23.000000000 +0000
@@ -226,7 +226,8 @@
     g_signal_connect (session, "request-queued",
         G_CALLBACK (midori_soup_session_settings_accept_language_cb), settings);
 
-    soup_session_add_feature (session, SOUP_SESSION_FEATURE (midori_hsts_new ()));
+    /* katze/midori-hsts.vala file is currently removed
+    soup_session_add_feature (session, SOUP_SESSION_FEATURE (midori_hsts_new ()));*/
 
     if (midori_debug ("headers"))
     {
