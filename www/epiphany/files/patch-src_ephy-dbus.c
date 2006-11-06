===================================================================
RCS file: /cvs/gnome/epiphany/src/ephy-dbus.c,v
retrieving revision 1.16.2.2
retrieving revision 1.16.2.3
diff -u -r1.16.2.2 -r1.16.2.3
--- src/ephy-dbus.c	2006/09/13 11:48:50	1.16.2.2
+++ src/ephy-dbus.c	2006/10/18 18:54:30	1.16.2.3
@@ -16,7 +16,7 @@
  *  along with this program; if not, write to the Free Software
  *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  *
- *  $Id: ephy-dbus.c,v 1.16.2.2 2006/09/13 11:48:50 chpe Exp $
+ *  $Id: ephy-dbus.c,v 1.16.2.3 2006/10/18 18:54:30 chpe Exp $
  */
 
 #include "config.h"
@@ -301,16 +301,6 @@
 	return TRUE;
 }
 
-static void
-ephy_dbus_disconnect_bus (DBusGConnection *bus)
-{
-	if (bus != NULL) {
-		dbus_connection_close
-			(dbus_g_connection_get_connection (bus));
-		dbus_g_connection_unref (bus);
-	}
-}
-
 /* Public methods */
 
 static void
@@ -337,7 +327,7 @@
 		dbus_connection_remove_filter
 			(dbus_g_connection_get_connection (priv->session_bus),
 			 session_filter_func, dbus);
-		ephy_dbus_disconnect_bus (priv->session_bus);
+		dbus_g_connection_unref (priv->session_bus);
 		priv->session_bus = NULL;
 	}
 
@@ -346,7 +336,7 @@
 		dbus_connection_remove_filter
 			(dbus_g_connection_get_connection (priv->system_bus),
 			 system_filter_func, dbus);
-		ephy_dbus_disconnect_bus (priv->system_bus);
+		dbus_g_connection_unref (priv->system_bus);
 		priv->system_bus = NULL;
 	}
 }
