--- polkit-gnome/polkit-gnome-action.c.orig	2008-07-22 17:00:53 UTC
+++ polkit-gnome/polkit-gnome-action.c
@@ -2062,6 +2062,8 @@ _button_clicked (GtkButton *button, PolKitGnomeAction 
         case POLKIT_RESULT_ONLY_VIA_SELF_AUTH_KEEP_ALWAYS:
                 /* g_debug ("blocking clicked"); */
                 g_signal_stop_emission_by_name (button, "clicked");
+		if (action->priv->polkit_action != NULL)
+			g_signal_emit (action, signals [AUTH_START_SIGNAL], 0);
                 break;
 
         default:
