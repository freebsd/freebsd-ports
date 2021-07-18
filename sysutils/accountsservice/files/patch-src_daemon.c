--- src/daemon.c.orig	2018-09-26 13:20:49 UTC
+++ src/daemon.c
@@ -79,7 +79,11 @@ typedef struct {
         GHashTable *extension_ifaces;
 } DaemonPrivate;
 
+#ifdef HAVE_SHADOW_H
 typedef struct passwd * (* EntryGeneratorFunc) (Daemon *, GHashTable *, gpointer *, struct spwd **shadow_entry);
+#else
+typedef struct passwd * (* EntryGeneratorFunc) (Daemon *, GHashTable *, gpointer *);
+#endif
 
 static void daemon_accounts_accounts_iface_init (AccountsAccountsIface *iface);
 
@@ -154,17 +158,25 @@ remove_cache_files (const gchar *user_name)
 }
 
 static struct passwd *
+#ifdef HAVE_SHADOW_H
 entry_generator_fgetpwent (Daemon       *daemon,
                            GHashTable   *users,
                            gpointer     *state,
                            struct spwd **spent)
+#else
+entry_generator_fgetpwent (Daemon       *daemon,
+                           GHashTable   *users,
+                           gpointer     *state)
+#endif
 {
         struct passwd *pwent;
 
+#ifdef HAVE_SHADOW_H
         struct {
                 struct spwd spbuf;
                 char buf[1024];
         } *shadow_entry_buffers;
+#endif
 
         struct {
                 FILE *fp;
@@ -175,6 +187,7 @@ entry_generator_fgetpwent (Daemon       *daemon,
         if (*state == NULL) {
                 GHashTable *shadow_users = NULL;
                 FILE *fp;
+#ifdef HAVE_SHADOW_H
                 struct spwd *shadow_entry;
 
                 fp = fopen (PATH_SHADOW, "r");
@@ -208,6 +221,7 @@ entry_generator_fgetpwent (Daemon       *daemon,
                         g_clear_pointer (&shadow_users, g_hash_table_unref);
                         return NULL;
                 }
+#endif
 
                 fp = fopen (PATH_PASSWD, "r");
                 if (fp == NULL) {
@@ -229,12 +243,17 @@ entry_generator_fgetpwent (Daemon       *daemon,
         if (g_hash_table_size (users) < MAX_LOCAL_USERS) {
                 pwent = fgetpwent (generator_state->fp);
                 if (pwent != NULL) {
+#ifdef HAVE_SHADOW_H
                         shadow_entry_buffers = g_hash_table_lookup (generator_state->users, pwent->pw_name);
 
                         if (shadow_entry_buffers != NULL) {
                             *spent = &shadow_entry_buffers->spbuf;
                         }
                         return pwent;
+#else
+                        if (!generator_state->users || g_hash_table_lookup (generator_state->users, pwent->pw_name))
+                            return pwent;
+#endif
                 }
         }
 
@@ -248,10 +267,16 @@ entry_generator_fgetpwent (Daemon       *daemon,
 }
 
 static struct passwd *
+#ifdef HAVE_SHADOW_H
 entry_generator_cachedir (Daemon       *daemon,
                           GHashTable   *users,
                           gpointer     *state,
                           struct spwd **shadow_entry)
+#else
+entry_generator_cachedir (Daemon       *daemon,
+                          GHashTable   *users,
+                          gpointer     *state)
+#endif
 {
         struct passwd *pwent;
         g_autoptr(GError) error = NULL;
@@ -293,7 +318,9 @@ entry_generator_cachedir (Daemon       *daemon,
                         errno = 0;
                         pwent = getpwnam (name);
                         if (pwent != NULL) {
+#ifdef HAVE_SHADOW_H
                                 *shadow_entry = getspnam (pwent->pw_name);
+#endif
 
                                 return pwent;
                         } else if (errno == 0) {
@@ -329,10 +356,16 @@ entry_generator_cachedir (Daemon       *daemon,
 }
 
 static struct passwd *
+#ifdef HAVE_SHADOW_H
 entry_generator_requested_users (Daemon       *daemon,
                                  GHashTable   *users,
                                  gpointer     *state,
                                  struct spwd **shadow_entry)
+#else
+entry_generator_requested_users (Daemon       *daemon,
+                                 GHashTable   *users,
+                                 gpointer     *state)
+#endif
 {
         DaemonPrivate *priv = daemon_get_instance_private (daemon);
         struct passwd *pwent;
@@ -360,7 +393,9 @@ entry_generator_requested_users (Daemon       *daemon,
                                 if (pwent == NULL) {
                                         g_debug ("user '%s' requested previously but not present on system", name);
                                 } else {
+#ifdef HAVE_SHADOW_H
                                         *shadow_entry = getspnam (pwent->pw_name);
+#endif
 
                                         return pwent;
                                 }
@@ -383,19 +418,29 @@ load_entries (Daemon             *daemon,
         DaemonPrivate *priv = daemon_get_instance_private (daemon);
         gpointer generator_state = NULL;
         struct passwd *pwent;
+#ifdef HAVE_SHADOW_H
         struct spwd *spent = NULL;
+#endif
         User *user = NULL;
 
         g_assert (entry_generator != NULL);
 
         for (;;) {
+#ifdef HAVE_SHADOW_H
                 spent = NULL;
                 pwent = entry_generator (daemon, users, &generator_state, &spent);
+#else
+                pwent = entry_generator (daemon, users, &generator_state);
+#endif
                 if (pwent == NULL)
                         break;
 
                 /* Skip system users... */
+#ifdef HAVE_SHADOW_H
                 if (!explicitly_requested && !user_classify_is_human (pwent->pw_uid, pwent->pw_name, pwent->pw_shell, spent? spent->sp_pwdp : NULL)) {
+#else
+                if (!explicitly_requested && !user_classify_is_human (pwent->pw_uid, pwent->pw_name, pwent->pw_shell, NULL)) {
+#endif
                         g_debug ("skipping user: %s", pwent->pw_name);
                         continue;
                 }
@@ -417,7 +462,11 @@ load_entries (Daemon             *daemon,
 
                         /* freeze & update users not already in the new list */
                         g_object_freeze_notify (G_OBJECT (user));
+#ifdef HAVE_SHADOW_H
                         user_update_from_pwent (user, pwent, spent);
+#else
+                        user_update_from_pwent (user, pwent);
+#endif
 
                         g_hash_table_insert (users, g_strdup (user_get_user_name (user)), user);
                         g_debug ("loaded user: %s", user_get_user_name (user));
@@ -823,15 +872,24 @@ throw_error (GDBusMethodInvocation *context,
 }
 
 static User *
+#ifdef HAVE_SHADOW_H
 add_new_user_for_pwent (Daemon        *daemon,
                         struct passwd *pwent,
                         struct spwd   *spent)
+#else
+add_new_user_for_pwent (Daemon        *daemon,
+                        struct passwd *pwent)
+#endif
 {
         DaemonPrivate *priv = daemon_get_instance_private (daemon);
         User *user;
 
         user = user_new (daemon, pwent->pw_uid);
+#ifdef HAVE_SHADOW_H
         user_update_from_pwent (user, pwent, spent);
+#else
+        user_update_from_pwent (user, pwent);
+#endif
         user_register (user);
 
         g_hash_table_insert (priv->users,
@@ -860,9 +918,13 @@ daemon_local_find_user_by_id (Daemon *daemon,
         user = g_hash_table_lookup (priv->users, pwent->pw_name);
 
         if (user == NULL) {
+#ifdef HAVE_SHADOW_H
                 struct spwd *spent;
                 spent = getspnam (pwent->pw_name);
                 user = add_new_user_for_pwent (daemon, pwent, spent);
+#else
+                user = add_new_user_for_pwent (daemon, pwent);
+#endif
 
                 priv->explicitly_requested_users = g_list_append (priv->explicitly_requested_users,
                                                                   g_strdup (pwent->pw_name));
@@ -888,9 +950,13 @@ daemon_local_find_user_by_name (Daemon      *daemon,
         user = g_hash_table_lookup (priv->users, pwent->pw_name);
 
         if (user == NULL) {
+#ifdef HAVE_SHADOW_H
                 struct spwd *spent;
                 spent = getspnam (pwent->pw_name);
                 user = add_new_user_for_pwent (daemon, pwent, spent);
+#else
+                user = add_new_user_for_pwent (daemon, pwent);
+#endif
 
                 priv->explicitly_requested_users = g_list_append (priv->explicitly_requested_users,
                                                                   g_strdup (pwent->pw_name));
@@ -1095,10 +1161,12 @@ daemon_create_user_authorized_cb (Daemon              
 
         sys_log (context, "create user '%s'", cd->user_name);
 
-        argv[0] = "/usr/sbin/useradd";
-        argv[1] = "-m";
-        argv[2] = "-c";
-        argv[3] = cd->real_name;
+        argv[0] = "/usr/sbin/pw";
+        argv[1] = "useradd";
+        argv[2] = cd->user_name;
+        argv[3] = "-m";
+        argv[4] = "-c";
+        argv[5] = cd->real_name;
         if (cd->account_type == ACCOUNT_TYPE_ADMINISTRATOR) {
                 if (EXTRA_ADMIN_GROUPS != NULL && EXTRA_ADMIN_GROUPS[0] != '\0')
                         admin_groups = g_strconcat (ADMIN_GROUP, ",",
@@ -1106,15 +1174,11 @@ daemon_create_user_authorized_cb (Daemon              
                 else
                         admin_groups = g_strdup (ADMIN_GROUP);
 
-                argv[4] = "-G";
-                argv[5] = admin_groups;
-                argv[6] = "--";
-                argv[7] = cd->user_name;
+                argv[6] = "-G";
+                argv[7] = admin_groups;
                 argv[8] = NULL;
         }
         else if (cd->account_type == ACCOUNT_TYPE_STANDARD) {
-                argv[4] = "--";
-                argv[5] = cd->user_name;
                 argv[6] = NULL;
         }
         else {
@@ -1281,7 +1345,7 @@ daemon_delete_user_authorized_cb (Daemon              
         DeleteUserData *ud = data;
         g_autoptr(GError) error = NULL;
         struct passwd *pwent;
-        const gchar *argv[6];
+        const gchar *argv[5];
         User *user;
 
         pwent = getpwuid (ud->uid);
@@ -1307,19 +1371,16 @@ daemon_delete_user_authorized_cb (Daemon              
 
         user_set_saved (user, FALSE);
 
-        argv[0] = "/usr/sbin/userdel";
+        argv[0] = "/usr/sbin/pw";
+        argv[1] = "userdel";
         if (ud->remove_files) {
-                argv[1] = "-f";
-                argv[2] = "-r";
-                argv[3] = "--";
-                argv[4] = pwent->pw_name;
-                argv[5] = NULL;
+                argv[2] = pwent->pw_name;
+                argv[3] = "-r";
+                argv[4] = NULL;
         }
         else {
-                argv[1] = "-f";
-                argv[2] = "--";
-                argv[3] = pwent->pw_name;
-                argv[4] = NULL;
+                argv[2] = pwent->pw_name;
+                argv[3] = NULL;
         }
 
         if (!spawn_with_login_uid (context, argv, &error)) {
