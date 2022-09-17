--- src/config/options.c.orig	2022-07-31 10:16:29 UTC
+++ src/config/options.c
@@ -892,6 +892,7 @@ change_hook_ui_double_esc(struct session *ses, struct 
 	return 0;
 }
 
+#ifdef CONFIG_MOUSE
 static int
 change_hook_ui_mouse_disable(struct session *ses, struct option *current, struct option *changed)
 {
@@ -907,6 +908,7 @@ change_hook_ui_mouse_disable(struct session *ses, stru
 	}
 	return 0;
 }
+#endif
 
 
 /** Make option templates visible or invisible in the option manager.
@@ -984,7 +986,9 @@ static const struct change_hook_info change_hooks[] = 
 	{ "ui.colors",			change_hook_ui_colors },
 	{ "ui.double_esc",		change_hook_ui_double_esc },
 	{ "ui.language",		change_hook_language },
+#ifdef CONFIG_MOUSE
 	{ "ui.mouse_disable",	change_hook_ui_mouse_disable },
+#endif
 	{ "ui",				change_hook_ui },
 	{ NULL,				NULL },
 };
