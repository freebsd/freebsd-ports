--- embed/ephy-embed-prefs.c.orig	2010-02-20 04:42:51.000000000 -0500
+++ embed/ephy-embed-prefs.c	2010-05-08 20:03:20.000000000 -0400
@@ -322,8 +322,10 @@ webkit_pref_callback_accept_languages (G
   langs_str = g_strjoinv (", ", langs);
 
   /* Update Soup session */
-  session = webkit_get_default_session ();
-  g_object_set (G_OBJECT (session), webkit_pref, langs_str, NULL);
+  if (strlen (langs_str) > 0) {
+      session = webkit_get_default_session ();
+      g_object_set (G_OBJECT (session), webkit_pref, langs_str, NULL);
+  }
 
   g_strfreev (langs);
   g_free (langs_str);
