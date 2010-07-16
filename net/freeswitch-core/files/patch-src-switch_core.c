--- src/switch_core.c	2010-06-22 17:19:36.000000000 -0400
+++ src/switch_core.c	2010-06-29 11:42:43.000000000 -0400
@@ -489,6 +489,14 @@
 #endif
 	}
 
+	if (!SWITCH_GLOBAL_dirs.voicemail_dir && (SWITCH_GLOBAL_dirs.voicemail_dir = (char *) malloc(BUFSIZE))) {
+#ifdef SWITCH_VOICEMAIL_DIR
+		switch_snprintf(SWITCH_GLOBAL_dirs.voicemail_dir, BUFSIZE, "%s", SWITCH_VOICEMAIL_DIR);
+#else
+		switch_snprintf(SWITCH_GLOBAL_dirs.voicemail_dir, BUFSIZE, "%s%svoicemail", storage_dir, SWITCH_PATH_SEPARATOR);
+#endif
+       }
+
 	if (!SWITCH_GLOBAL_dirs.db_dir && (SWITCH_GLOBAL_dirs.db_dir = (char *) malloc(BUFSIZE))) {
 #ifdef SWITCH_DB_DIR
 		switch_snprintf(SWITCH_GLOBAL_dirs.db_dir, BUFSIZE, "%s", SWITCH_DB_DIR);
@@ -546,6 +554,8 @@
 	switch_assert(SWITCH_GLOBAL_dirs.recordings_dir);
 	switch_assert(SWITCH_GLOBAL_dirs.sounds_dir);
 	switch_assert(SWITCH_GLOBAL_dirs.temp_dir);
+	switch_assert(SWITCH_GLOBAL_dirs.storage_dir);
+	switch_assert(SWITCH_GLOBAL_dirs.voicemail_dir);
 }
 
 SWITCH_DECLARE(int32_t) set_high_priority(void)
@@ -1240,6 +1250,8 @@
 	switch_dir_make_recursive(SWITCH_GLOBAL_dirs.recordings_dir, SWITCH_DEFAULT_DIR_PERMS, runtime.memory_pool);
 	switch_dir_make_recursive(SWITCH_GLOBAL_dirs.sounds_dir, SWITCH_DEFAULT_DIR_PERMS, runtime.memory_pool);
 	switch_dir_make_recursive(SWITCH_GLOBAL_dirs.temp_dir, SWITCH_DEFAULT_DIR_PERMS, runtime.memory_pool);
+	switch_dir_make_recursive(SWITCH_GLOBAL_dirs.storage_dir, SWITCH_DEFAULT_DIR_PERMS, runtime.memory_pool);
+	switch_dir_make_recursive(SWITCH_GLOBAL_dirs.voicemail_dir, SWITCH_DEFAULT_DIR_PERMS, runtime.memory_pool);
 
 	switch_mutex_init(&runtime.uuid_mutex, SWITCH_MUTEX_NESTED, runtime.memory_pool);
 
@@ -1273,7 +1285,9 @@
 	switch_find_local_ip(guess_ip, sizeof(guess_ip), NULL, AF_INET6);
 	switch_core_set_variable("local_ip_v6", guess_ip);
 	switch_core_set_variable("base_dir", SWITCH_GLOBAL_dirs.base_dir);
+	switch_core_set_variable("storage_dir", SWITCH_GLOBAL_dirs.storage_dir);
 	switch_core_set_variable("recordings_dir", SWITCH_GLOBAL_dirs.recordings_dir);
+	switch_core_set_variable("voicemail_dir", SWITCH_GLOBAL_dirs.voicemail_dir);
 	switch_core_set_variable("sound_prefix", SWITCH_GLOBAL_dirs.sounds_dir);
 	switch_core_set_variable("sounds_dir", SWITCH_GLOBAL_dirs.sounds_dir);
 	switch_core_set_serial();
@@ -1417,6 +1431,8 @@
 					switch_set_flag((&runtime), SCF_EARLY_HANGUP);
 				} else if (!strcasecmp(var, "colorize-console") && switch_true(val)) {
 					runtime.colorize_console = SWITCH_TRUE;
+				} else if (!strcasecmp(var, "storage-dir") && !zstr(val)) {
+					runtime.storage_dir = switch_core_strdup(runtime.memory_pool, val);
 				} else if (!strcasecmp(var, "mailer-app") && !zstr(val)) {
 					runtime.mailer_app = switch_core_strdup(runtime.memory_pool, val);
 				} else if (!strcasecmp(var, "mailer-app-args") && val) {
@@ -1867,6 +1883,8 @@
 	switch_safe_free(SWITCH_GLOBAL_dirs.script_dir);
 	switch_safe_free(SWITCH_GLOBAL_dirs.htdocs_dir);
 	switch_safe_free(SWITCH_GLOBAL_dirs.grammar_dir);
+	switch_safe_free(SWITCH_GLOBAL_dirs.storage_dir);
+	switch_safe_free(SWITCH_GLOBAL_dirs.voicemail_dir);
 	switch_safe_free(SWITCH_GLOBAL_dirs.recordings_dir);
 	switch_safe_free(SWITCH_GLOBAL_dirs.sounds_dir);
 	switch_safe_free(SWITCH_GLOBAL_dirs.temp_dir);
