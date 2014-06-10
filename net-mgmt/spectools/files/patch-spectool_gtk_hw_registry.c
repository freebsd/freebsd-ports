--- spectool_gtk_hw_registry.c.orig	2014-06-10 21:02:47.000000000 +0200
+++ spectool_gtk_hw_registry.c	2014-06-10 21:05:11.000000000 +0200
@@ -326,10 +326,10 @@ gboolean wdr_bcpoll(GIOChannel *ioch, GI
 
 spectool_phy *wdr_get_phy(spectool_device_registry *wdr, int slot) {
 	if (slot < 0 || slot > wdr->max_dev)
-		return;
+		return NULL;
 
 	if (wdr->devices[slot] == NULL)
-		return;
+		return NULL;
 
 	return wdr->devices[slot]->phydev;
 }
@@ -523,10 +523,10 @@ gboolean wdr_netrpoll(GIOChannel *ioch, 
 	char err[SPECTOOL_ERROR_MAX];
 
 	if (wdrpr->slot < 0 || wdrpr->slot > wdrpr->wdr->max_dev)
-		return;
+		return FALSE;
 
 	if (wdrpr->wdr->netservers[wdrpr->slot] == NULL)
-		return;
+		return FALSE;
 
 	sr = wdrpr->wdr->netservers[wdrpr->slot]->srv;
 
@@ -537,7 +537,7 @@ gboolean wdr_netrpoll(GIOChannel *ioch, 
 			Spectool_Alert_Dialog(err);
 
 			wdr_close_net(wdrpr->wdr, wdrpr->slot);
-			return;
+			return FALSE;
 		}
 
 	} while ((r & SPECTOOL_NETCLI_POLL_ADDITIONAL));
