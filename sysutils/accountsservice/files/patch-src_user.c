--- src/user.c.orig	2018-04-20 20:52:07 UTC
+++ src/user.c
@@ -138,9 +138,14 @@ user_reset_icon_file (User *user)
 }
 
 void
+#ifdef HAVE_SHADOW_H
 user_update_from_pwent (User          *user,
                         struct passwd *pwent,
                         struct spwd   *spent)
+#else
+user_update_from_pwent (User          *user,
+                        struct passwd *pwent)
+#endif
 {
         g_autofree gchar *real_name = NULL;
         gboolean is_system_account;
@@ -199,8 +204,10 @@ user_update_from_pwent (User          *user,
         accounts_user_set_shell (ACCOUNTS_USER (user), pwent->pw_shell);
 
         passwd = NULL;
+#ifdef HAVE_SHADOW_H
         if (spent)
                 passwd = spent->sp_pwdp;
+#endif
 
         if (passwd && passwd[0] == '!') {
                 locked = TRUE;
@@ -218,6 +225,7 @@ user_update_from_pwent (User          *user,
                 mode = PASSWORD_MODE_NONE;
         }
 
+#ifdef HAVE_SHADOW_H
         if (spent) {
                 if (spent->sp_lstchg == 0) {
                         mode = PASSWORD_MODE_SET_AT_LOGIN;
@@ -231,6 +239,9 @@ user_update_from_pwent (User          *user,
                 user->days_after_expiration_until_lock = spent->sp_inact;
                 user->account_expiration_policy_known = TRUE;
         }
+#else
+        user->expiration_time = pwent->pw_expire;
+#endif
 
         accounts_user_set_password_mode (ACCOUNTS_USER (user), mode);
         is_system_account = !user_classify_is_human (accounts_user_get_uid (ACCOUNTS_USER (user)),
@@ -813,11 +824,11 @@ user_change_real_name_authorized_cb (Daemon           
                          accounts_user_get_uid (ACCOUNTS_USER (user)),
                          name);
 
-                argv[0] = "/usr/sbin/usermod";
-                argv[1] = "-c";
-                argv[2] = name;
-                argv[3] = "--";
-                argv[4] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                argv[0] = "/usr/sbin/pw";
+                argv[1] = "usermod";
+                argv[2] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                argv[3] = "-c";
+                argv[4] = name;
                 argv[5] = NULL;
 
                 if (!spawn_with_login_uid (context, argv, &error)) {
@@ -882,11 +893,11 @@ user_change_user_name_authorized_cb (Daemon           
                          accounts_user_get_uid (ACCOUNTS_USER (user)),
                          name);
 
-                argv[0] = "/usr/sbin/usermod";
-                argv[1] = "-l";
-                argv[2] = name;
-                argv[3] = "--";
-                argv[4] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                argv[0] = "/usr/sbin/pw";
+                argv[1] = "usermod";
+                argv[2] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                argv[3] = "-n";
+                argv[4] = name;
                 argv[5] = NULL;
 
                 if (!spawn_with_login_uid (context, argv, &error)) {
@@ -1183,7 +1194,7 @@ user_change_home_dir_authorized_cb (Daemon            
 {
         gchar *home_dir = data;
         g_autoptr(GError) error = NULL;
-        const gchar *argv[7];
+        const gchar *argv[6];
 
         if (g_strcmp0 (accounts_user_get_home_directory (ACCOUNTS_USER (user)), home_dir) != 0) {
                 sys_log (context,
@@ -1192,13 +1203,12 @@ user_change_home_dir_authorized_cb (Daemon            
                          accounts_user_get_uid (ACCOUNTS_USER (user)),
                          home_dir);
 
-                argv[0] = "/usr/sbin/usermod";
-                argv[1] = "-m";
-                argv[2] = "-d";
-                argv[3] = home_dir;
-                argv[4] = "--";
-                argv[5] = accounts_user_get_user_name (ACCOUNTS_USER (user));
-                argv[6] = NULL;
+                argv[0] = "/usr/sbin/pw";
+                argv[1] = "-d";
+                argv[2] = home_dir;
+                argv[3] = "-n";
+                argv[4] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                argv[5] = NULL;
 
                 if (!spawn_with_login_uid (context, argv, &error)) {
                         throw_error (context, ERROR_FAILED, "running '%s' failed: %s", argv[0], error->message);
@@ -1249,11 +1259,11 @@ user_change_shell_authorized_cb (Daemon               
                          accounts_user_get_uid (ACCOUNTS_USER (user)),
                          shell);
 
-                argv[0] = "/usr/sbin/usermod";
-                argv[1] = "-s";
-                argv[2] = shell;
-                argv[3] = "--";
-                argv[4] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                argv[0] = "/usr/sbin/pw";
+                argv[1] = "usermod";
+                argv[2] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                argv[3] = "-s";
+                argv[4] = shell;
                 argv[5] = NULL;
 
                 if (!spawn_with_login_uid (context, argv, &error)) {
@@ -1456,7 +1466,7 @@ user_change_locked_authorized_cb (Daemon              
 {
         gboolean locked = GPOINTER_TO_INT (data);
         g_autoptr(GError) error = NULL;
-        const gchar *argv[5];
+        const gchar *argv[4];
 
         if (accounts_user_get_locked (ACCOUNTS_USER (user)) != locked) {
                 sys_log (context,
@@ -1464,11 +1474,10 @@ user_change_locked_authorized_cb (Daemon              
                          locked ? "locking" : "unlocking",
                          accounts_user_get_user_name (ACCOUNTS_USER (user)),
                          accounts_user_get_uid (ACCOUNTS_USER (user)));
-                argv[0] = "/usr/sbin/usermod";
-                argv[1] = locked ? "-L" : "-U";
-                argv[2] = "--";
-                argv[3] = accounts_user_get_user_name (ACCOUNTS_USER (user));
-                argv[4] = NULL;
+                argv[0] = "/usr/sbin/pw";
+                argv[1] = locked ? "lock" : "unlock";
+                argv[2] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                argv[3] = NULL;
 
                 if (!spawn_with_login_uid (context, argv, &error)) {
                         throw_error (context, ERROR_FAILED, "running '%s' failed: %s", argv[0], error->message);
@@ -1589,11 +1598,11 @@ user_change_account_type_authorized_cb (Daemon        
 
                 g_free (groups);
 
-                argv[0] = "/usr/sbin/usermod";
-                argv[1] = "-G";
-                argv[2] = str->str;
-                argv[3] = "--";
-                argv[4] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                argv[0] = "/usr/sbin/pw";
+                argv[1] = "usermod";
+                argv[2] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                argv[3] = "-G";
+                argv[4] = str->str;
                 argv[5] = NULL;
 
                 if (!spawn_with_login_uid (context, argv, &error)) {
@@ -1643,7 +1652,7 @@ user_change_password_mode_authorized_cb (Daemon       
 {
         PasswordMode mode = GPOINTER_TO_INT (data);
         g_autoptr(GError) error = NULL;
-        const gchar *argv[6];
+        const gchar *argv[5];
 
         if (((PasswordMode) accounts_user_get_password_mode (ACCOUNTS_USER (user))) != mode) {
                 sys_log (context,
@@ -1658,10 +1667,8 @@ user_change_password_mode_authorized_cb (Daemon       
                     mode == PASSWORD_MODE_NONE) {
 
                         argv[0] = "/usr/bin/passwd";
-                        argv[1] = "-d";
-                        argv[2] = "--";
-                        argv[3] = accounts_user_get_user_name (ACCOUNTS_USER (user));
-                        argv[4] = NULL;
+                        argv[1] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                        argv[2] = NULL;
 
                         if (!spawn_with_login_uid (context, argv, &error)) {
                                 throw_error (context, ERROR_FAILED, "running '%s' failed: %s", argv[0], error->message);
@@ -1669,12 +1676,11 @@ user_change_password_mode_authorized_cb (Daemon       
                         }
 
                         if (mode == PASSWORD_MODE_SET_AT_LOGIN) {
-                                argv[0] = "/usr/bin/chage";
-                                argv[1] = "-d";
+                                argv[0] = "/usr/bin/chpass";
+                                argv[1] = "-e";
                                 argv[2] = "0";
-                                argv[3] = "--";
-                                argv[4] = accounts_user_get_user_name (ACCOUNTS_USER (user));
-                                argv[5] = NULL;
+                                argv[3] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                                argv[4] = NULL;
 
                                 if (!spawn_with_login_uid (context, argv, &error)) {
                                         throw_error (context, ERROR_FAILED, "running '%s' failed: %s", argv[0], error->message);
@@ -1690,11 +1696,10 @@ user_change_password_mode_authorized_cb (Daemon       
                         accounts_user_set_locked (ACCOUNTS_USER (user), FALSE);
                 }
                 else if (accounts_user_get_locked (ACCOUNTS_USER (user))) {
-                        argv[0] = "/usr/sbin/usermod";
-                        argv[1] = "-U";
-                        argv[2] = "--";
-                        argv[3] = accounts_user_get_user_name (ACCOUNTS_USER (user));
-                        argv[4] = NULL;
+                        argv[0] = "/usr/sbin/pw";
+                        argv[1] = "unlock";
+                        argv[2] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                        argv[3] = NULL;
 
                         if (!spawn_with_login_uid (context, argv, &error)) {
                                 throw_error (context, ERROR_FAILED, "running '%s' failed: %s", argv[0], error->message);
@@ -1759,7 +1764,7 @@ user_change_password_authorized_cb (Daemon            
 {
         gchar **strings = data;
         g_autoptr(GError) error = NULL;
-        const gchar *argv[6];
+        const gchar *argv[5];
 
         sys_log (context,
                  "set password and hint of user '%s' (%d)",
@@ -1768,12 +1773,11 @@ user_change_password_authorized_cb (Daemon            
 
         g_object_freeze_notify (G_OBJECT (user));
 
-        argv[0] = "/usr/sbin/usermod";
+        argv[0] = "/usr/bin/chpass";
         argv[1] = "-p";
         argv[2] = strings[0];
-        argv[3] = "--";
-        argv[4] = accounts_user_get_user_name (ACCOUNTS_USER (user));
-        argv[5] = NULL;
+        argv[3] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+        argv[4] = NULL;
 
         if (!spawn_with_login_uid (context, argv, &error)) {
                 throw_error (context, ERROR_FAILED, "running '%s' failed: %s", argv[0], error->message);
