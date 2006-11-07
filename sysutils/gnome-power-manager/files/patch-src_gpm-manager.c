Index: gpm-manager.c
===================================================================
RCS file: /cvs/gnome/gnome-power-manager/src/gpm-manager.c,v
retrieving revision 1.172.2.2
diff -u -r1.172.2.2 gpm-manager.c
--- src/gpm-manager.c	19 Oct 2006 16:47:59 -0000	1.172.2.2
+++ src/gpm-manager.c	6 Nov 2006 19:02:16 -0000
@@ -680,6 +680,10 @@
 			manager->priv->dpms_throttle_id = 0;
 		}
 	} else {
+		/* if throttle already exists then remove */
+		if (manager->priv->dpms_throttle_id > 0) {
+			gpm_screensaver_remove_throttle (manager->priv->screensaver, manager->priv->dpms_throttle_id);
+		}
 		manager->priv->dpms_throttle_id = gpm_screensaver_add_throttle (manager->priv->screensaver, _("Display power management activated"));
 	}
 }
@@ -2863,6 +2867,8 @@
 	/* Do we ignore inhibit requests? */
 	manager->priv->ignore_inhibits = gconf_client_get_bool (manager->priv->gconf_client,
 								GPM_PREF_IGNORE_INHIBITS, NULL);
+	/* set no throttle */
+	manager->priv->dpms_throttle_id = -1;
 }
 
 /**
