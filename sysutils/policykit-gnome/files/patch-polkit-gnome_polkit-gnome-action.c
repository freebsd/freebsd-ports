--- polkit-gnome/polkit-gnome-action.c.old	2009-06-28 12:54:35.000000000 +0200
+++ polkit-gnome/polkit-gnome-action.c	2009-06-28 12:55:07.000000000 +0200
@@ -2062,6 +2062,8 @@
         case POLKIT_RESULT_ONLY_VIA_SELF_AUTH_KEEP_ALWAYS:
                 /* g_debug ("blocking clicked"); */
                 g_signal_stop_emission_by_name (button, "clicked");
+		if (action->priv->polkit_action != NULL)
+			g_signal_emit (action, signals [AUTH_START_SIGNAL], 0);
                 break;
 
         default:


