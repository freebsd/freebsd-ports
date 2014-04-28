--- src/gpm-control.c.orig	2014-04-06 20:51:17.215212718 +0000
+++ src/gpm-control.c	2014-04-06 20:53:11.708207714 +0000
@@ -289,7 +289,11 @@
 		g_object_unref(proxy);
 	}
 	else {
+#ifdef HAVE_OLD_UPOWER
 		ret = up_client_suspend_sync (control->priv->client, NULL, error);
+#else
+		ret = FALSE;
+#endif
 	}
 
 	egg_debug ("emitting resume");
@@ -399,7 +403,11 @@
 		}
 	}
 	else {
+#ifdef HAVE_OLD_UPOWER
 		ret = up_client_hibernate_sync (control->priv->client, NULL, error);
+#else
+		ret = FALSE;
+#endif
 	}
 
 	egg_debug ("emitting resume");
