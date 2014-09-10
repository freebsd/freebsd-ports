--- src/gpm-control.c.orig	2014-04-20 19:32:33.624174324 +0000
+++ src/gpm-control.c	2014-04-20 19:33:52.860168682 +0000
@@ -290,7 +290,11 @@
 		g_object_unref(proxy);
 	}
 	else {
+#ifdef HAVE_OLD_UPOWER		
 		ret = up_client_suspend_sync (control->priv->client, NULL, error);
+#else
+                ret = FALSE;
+#endif
 	}
 
 	egg_debug ("emitting resume");
@@ -400,7 +404,11 @@
 		}
 	}
 	else {
+#ifdef HAVE_OLD_UPOWER		
 		ret = up_client_hibernate_sync (control->priv->client, NULL, error);
+#else
+                ret = FALSE;
+#endif		
 	}
 
 	egg_debug ("emitting resume");
