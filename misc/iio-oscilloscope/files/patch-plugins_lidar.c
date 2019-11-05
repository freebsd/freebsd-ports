--- plugins/lidar.c.orig	2019-10-31 18:10:53 UTC
+++ plugins/lidar.c
@@ -112,7 +112,7 @@ static void auto_cfg_set_cb(void)
 static void auto_cfg_button_changed_cb(GtkSpinButton *btn)
 {
 	// Force the buttons value to have a valid permutation of (0, 1, 2, 3)
-	int i, j, idx;
+	int i, j, idx = 0;
 	int old_val;
 	int crt_val = gtk_spin_button_get_value_as_int(btn);
 
