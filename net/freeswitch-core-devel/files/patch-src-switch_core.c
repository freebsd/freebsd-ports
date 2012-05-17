--- src/switch_core.c
+++ src/switch_core.c
@@ -646,6 +646,7 @@ SWITCH_DECLARE(void) switch_core_set_globals(void)
 	switch_assert(SWITCH_GLOBAL_dirs.recordings_dir);
 	switch_assert(SWITCH_GLOBAL_dirs.sounds_dir);
 	switch_assert(SWITCH_GLOBAL_dirs.temp_dir);
+	switch_assert(SWITCH_GLOBAL_dirs.storage_dir);
 }
 
 
@@ -1450,7 +1451,7 @@ SWITCH_DECLARE(switch_status_t) switch_core_init(switch_core_flag_t flags, switc
 	switch_dir_make_recursive(SWITCH_GLOBAL_dirs.recordings_dir, SWITCH_DEFAULT_DIR_PERMS, runtime.memory_pool);
 	switch_dir_make_recursive(SWITCH_GLOBAL_dirs.sounds_dir, SWITCH_DEFAULT_DIR_PERMS, runtime.memory_pool);
 	switch_dir_make_recursive(SWITCH_GLOBAL_dirs.temp_dir, SWITCH_DEFAULT_DIR_PERMS, runtime.memory_pool);
-
+	switch_dir_make_recursive(SWITCH_GLOBAL_dirs.storage_dir, SWITCH_DEFAULT_DIR_PERMS, runtime.memory_pool);
 
 	switch_mutex_init(&runtime.uuid_mutex, SWITCH_MUTEX_NESTED, runtime.memory_pool);
 
@@ -1488,6 +1489,7 @@ SWITCH_DECLARE(switch_status_t) switch_core_init(switch_core_flag_t flags, switc
 	switch_find_local_ip(guess_ip, sizeof(guess_ip), NULL, AF_INET6);
 	switch_core_set_variable("local_ip_v6", guess_ip);
 	switch_core_set_variable("base_dir", SWITCH_GLOBAL_dirs.base_dir);
+	switch_core_set_variable("storage_dir", SWITCH_GLOBAL_dirs.storage_dir);
 	switch_core_set_variable("recordings_dir", SWITCH_GLOBAL_dirs.recordings_dir);
 	switch_core_set_variable("sound_prefix", SWITCH_GLOBAL_dirs.sounds_dir);
 	switch_core_set_variable("sounds_dir", SWITCH_GLOBAL_dirs.sounds_dir);
@@ -1728,6 +1730,8 @@ static void switch_load_core_config(const char *file)
 					switch_set_flag((&runtime), SCF_EARLY_HANGUP);
 				} else if (!strcasecmp(var, "colorize-console") && switch_true(val)) {
 					runtime.colorize_console = SWITCH_TRUE;
+				} else if (!strcasecmp(var, "storage-dir") && !zstr(val)) {
+					runtime.storage_dir = switch_core_strdup(runtime.memory_pool, val);
 				} else if (!strcasecmp(var, "core-db-pre-trans-execute") && !zstr(val)) {
 					runtime.core_db_pre_trans_execute = switch_core_strdup(runtime.memory_pool, val);
 				} else if (!strcasecmp(var, "core-db-post-trans-execute") && !zstr(val)) {
