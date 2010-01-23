--- src/users/user-settings.c.orig	2009-12-15 05:17:23.000000000 -0800
+++ src/users/user-settings.c	2010-01-20 22:25:39.000000000 -0800
@@ -29,7 +29,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <stdlib.h>
-#include <utmp.h>
+#include <sys/param.h>
 #include <ctype.h>
 
 #include "users-table.h"
@@ -367,7 +367,7 @@
 {
 	gint max_len;
 #ifdef __FreeBSD__
-	max_len = UT_NAMESIZE;
+	max_len = MAXLOGNAME - 1;
 #else
 	struct utmp ut;
 
@@ -819,10 +819,10 @@
 		password_changed = GPOINTER_TO_INT (g_object_get_data (G_OBJECT (widget), "changed"));
 
 		if (password_changed)
-			oobs_user_set_password (user, gtk_entry_get_text (GTK_ENTRY (widget)));
+			oobs_user_set_crypted_password (user, gtk_entry_get_text (GTK_ENTRY (widget)));
 	} else {
 		widget = gst_dialog_get_widget (tool->main_dialog, "user_settings_random_passwd");
-		oobs_user_set_password (user, gtk_entry_get_text (GTK_ENTRY (widget)));
+		oobs_user_set_crypted_password (user, gtk_entry_get_text (GTK_ENTRY (widget)));
 	}
 
 	group = get_main_group (oobs_user_get_login_name (user));
