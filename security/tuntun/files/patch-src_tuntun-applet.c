--- src/tuntun-applet.c.orig	2011-08-16 15:08:48.000000000 +0200
+++ src/tuntun-applet.c	2011-08-16 15:32:49.000000000 +0200
@@ -705,14 +705,14 @@ static void tuntun_panel_applet_on_conne
 			NotifyNotification* _tmp2_;
 			char* _tmp1_;
 			char* _tmp0_;
-			notification = (_tmp2_ = notify_notification_new (tuntun_connection_info_get_name (tuntun_connection_get_info (connection)), _tmp0_ = g_strdup_printf (_ ("connection established\nassigned ip: %s"), tuntun_connection_info_get_assigned_ip (tuntun_connection_get_info (connection))), _tmp1_ = tuntun_utils_get_image_path (TUNTUN_CONSTANTS_IMAGES_CONNECTION_STATUS_CONNECTED), (GtkWidget*) self), _g_object_unref0 (notification), _tmp2_);
+			notification = (_tmp2_ = notify_notification_new (tuntun_connection_info_get_name (tuntun_connection_get_info (connection)), _tmp0_ = g_strdup_printf (_ ("connection established\nassigned ip: %s"), tuntun_connection_info_get_assigned_ip (tuntun_connection_get_info (connection))), _tmp1_ = tuntun_utils_get_image_path (TUNTUN_CONSTANTS_IMAGES_CONNECTION_STATUS_CONNECTED)), _g_object_unref0 (notification), _tmp2_);
 			_g_free0 (_tmp1_);
 			_g_free0 (_tmp0_);
 		} else {
 			if (tuntun_connection_get_status (connection) == TUNTUN_CONNECTION_STATES_DISCONNECTED) {
 				NotifyNotification* _tmp4_;
 				char* _tmp3_;
-				notification = (_tmp4_ = notify_notification_new (tuntun_connection_info_get_name (tuntun_connection_get_info (connection)), _ ("connection closed"), _tmp3_ = tuntun_utils_get_image_path (TUNTUN_CONSTANTS_IMAGES_CONNECTION_STATUS_DISCONNECTED), (GtkWidget*) self), _g_object_unref0 (notification), _tmp4_);
+				notification = (_tmp4_ = notify_notification_new (tuntun_connection_info_get_name (tuntun_connection_get_info (connection)), _ ("connection closed"), _tmp3_ = tuntun_utils_get_image_path (TUNTUN_CONSTANTS_IMAGES_CONNECTION_STATUS_DISCONNECTED)), _g_object_unref0 (notification), _tmp4_);
 				_g_free0 (_tmp3_);
 			}
 		}
