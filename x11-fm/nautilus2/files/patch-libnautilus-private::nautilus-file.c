--- libnautilus-private/nautilus-file.c.orig	Sun Sep 21 22:14:27 2003
+++ libnautilus-private/nautilus-file.c	Sun Sep 21 22:15:32 2003
@@ -357,8 +357,6 @@
 				relative_uri_tmp++;
 			}
 			relative_uri = strdup (relative_uri_tmp);
-		} else {
-			g_assert_not_reached ();
 		}
 	}
 
