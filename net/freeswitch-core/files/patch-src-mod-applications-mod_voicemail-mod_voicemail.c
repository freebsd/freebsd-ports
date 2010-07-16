--- src/mod/applications/mod_voicemail/mod_voicemail.c	2010-06-22 17:19:34.000000000 -0400
+++ src/mod/applications/mod_voicemail/mod_voicemail.c	2010-07-02 13:03:12.000000000 -0400
@@ -119,7 +119,7 @@
 	char *operator_ext;
 	char *vmain_ext;
 	char *tone_spec;
-	char *storage_dir;
+	char *voicemail_dir;
 	char *callback_dialplan;
 	char *callback_context;
 	char *email_body;
@@ -539,8 +539,8 @@
 
 	SWITCH_CONFIG_SET_ITEM(profile->config[i++], "tone-spec", SWITCH_CONFIG_STRING, CONFIG_RELOADABLE,
 						   &profile->tone_spec, "%(1000, 0, 640)", &profile->config_str_pool, NULL, NULL);
-	SWITCH_CONFIG_SET_ITEM(profile->config[i++], "storage-dir", SWITCH_CONFIG_STRING, CONFIG_RELOADABLE,
-						   &profile->storage_dir, "", &profile->config_str_pool, NULL, NULL);
+	SWITCH_CONFIG_SET_ITEM(profile->config[i++], "voicemail-dir", SWITCH_CONFIG_STRING, CONFIG_RELOADABLE,
+						   &profile->voicemail_dir, "", &profile->config_str_pool, NULL, NULL);
 	SWITCH_CONFIG_SET_ITEM(profile->config[i++], "callback-dialplan", SWITCH_CONFIG_STRING, CONFIG_RELOADABLE,
 						   &profile->callback_dialplan, "XML", &profile->config_str_pool, NULL, NULL);
 	SWITCH_CONFIG_SET_ITEM(profile->config[i++], "callback-context", SWITCH_CONFIG_STRING, CONFIG_RELOADABLE,
@@ -1706,7 +1706,7 @@
 	char *vm_email = NULL, *email_addr = NULL;
 	char *convert_cmd = profile->convert_cmd;
 	char *convert_ext = profile->convert_ext;
-	char *vm_storage_dir = NULL;
+	char *vm_voicemail_dir = NULL;
 	char global_buf[2] = "";
 	switch_input_args_t args = { 0 };
 	const char *caller_id_name = NULL;
@@ -2149,8 +2149,8 @@
 						convert_cmd = switch_core_session_strdup(session, val);
 					} else if (!strcasecmp(var, "vm-convert-ext")) {
 						convert_ext = switch_core_session_strdup(session, val);
-					} else if (!strcasecmp(var, "storage-dir")) {
-						vm_storage_dir = switch_core_session_strdup(session, val);
+					} else if (!strcasecmp(var, "voicemail-dir")) {
+						vm_voicemail_dir = switch_core_session_strdup(session, val);
 
 					} else if (!strcasecmp(var, "timezone")) {
 						switch_channel_set_variable(channel, var, val);
@@ -2211,14 +2211,14 @@
 
 				if (auth) {
 					if (!dir_path) {
-						if (!zstr(vm_storage_dir)) {
-							dir_path = switch_core_session_sprintf(session, "%s%s%s", vm_storage_dir, SWITCH_PATH_SEPARATOR, myid);
-						} else if (!zstr(profile->storage_dir)) {
+						if (!zstr(vm_voicemail_dir)) {
+							dir_path = switch_core_session_sprintf(session, "%s%s%s", vm_voicemail_dir, SWITCH_PATH_SEPARATOR, myid);
+						} else if (!zstr(profile->voicemail_dir)) {
 							dir_path =
-								switch_core_session_sprintf(session, "%s%s%s%s%s", profile->storage_dir, SWITCH_PATH_SEPARATOR, domain_name,
+								switch_core_session_sprintf(session, "%s%s%s%s%s", profile->voicemail_dir, SWITCH_PATH_SEPARATOR, domain_name,
 															SWITCH_PATH_SEPARATOR, myid);
 						} else {
-							dir_path = switch_core_session_sprintf(session, "%s%svoicemail%s%s%s%s%s%s", SWITCH_GLOBAL_dirs.storage_dir,
+							dir_path = switch_core_session_sprintf(session, "%s%s%s%s%s%s%s%s", SWITCH_GLOBAL_dirs.voicemail_dir,
 																   SWITCH_PATH_SEPARATOR,
 																   SWITCH_PATH_SEPARATOR,
 																   profile->name, SWITCH_PATH_SEPARATOR, domain_name, SWITCH_PATH_SEPARATOR, myid);
@@ -2293,7 +2293,7 @@
 	int send_notify = 0;
 	int insert_db = 1;
 	int email_attach = 0;
-	char *vm_storage_dir = NULL;
+	char *vm_voicemail_dir = NULL;
 	char *myfolder = "inbox";
 	int priority = 3;
 	const char *tmp;
@@ -2366,12 +2366,12 @@
 
 	switch_log_printf(SWITCH_CHANNEL_LOG, SWITCH_LOG_DEBUG, "Deliver VM to %s@%s\n", myid, domain_name);
 
-	if (!zstr(vm_storage_dir)) {
-		dir_path = switch_mprintf("%s%s%s", vm_storage_dir, SWITCH_PATH_SEPARATOR, myid);
-	} else if (!zstr(profile->storage_dir)) {
-		dir_path = switch_mprintf("%s%s%s%s%s", profile->storage_dir, SWITCH_PATH_SEPARATOR, domain_name, SWITCH_PATH_SEPARATOR, myid);
+	if (!zstr(vm_voicemail_dir)) {
+		dir_path = switch_mprintf("%s%s%s", vm_voicemail_dir, SWITCH_PATH_SEPARATOR, myid);
+	} else if (!zstr(profile->voicemail_dir)) {
+		dir_path = switch_mprintf("%s%s%s%s%s", profile->voicemail_dir, SWITCH_PATH_SEPARATOR, domain_name, SWITCH_PATH_SEPARATOR, myid);
 	} else {
-		dir_path = switch_mprintf("%s%svoicemail%s%s%s%s%s%s", SWITCH_GLOBAL_dirs.storage_dir,
+		dir_path = switch_mprintf("%s%s%s%s%s%s%s%s", SWITCH_GLOBAL_dirs.voicemail_dir,
 								  SWITCH_PATH_SEPARATOR,
 								  SWITCH_PATH_SEPARATOR, profile->name, SWITCH_PATH_SEPARATOR, domain_name, SWITCH_PATH_SEPARATOR, myid);
 	}
@@ -2822,7 +2822,7 @@
 	char date[80] = "";
 	switch_size_t retsize;
 	switch_time_t ts = switch_micro_time_now();
-	char *vm_storage_dir = NULL;
+	char *vm_voicemail_dir = NULL;
 	char *record_macro = VM_RECORD_MESSAGE_MACRO;
 	int send_main = 0;
 	int send_notify = 0;
@@ -2876,8 +2876,8 @@
 						email_addr = switch_core_session_strdup(session, val);
 					} else if (!strcasecmp(var, "vm-email-all-messages") && (send_main = switch_true(val))) {
 						send_mail++;
-					} else if (!strcasecmp(var, "storage-dir")) {
-						vm_storage_dir = switch_core_session_strdup(session, val);
+					} else if (!strcasecmp(var, "voicemail-dir")) {
+						vm_voicemail_dir = switch_core_session_strdup(session, val);
 					} else if (!strcasecmp(var, "vm-notify-email-all-messages") && (send_notify = switch_true(val))) {
 						send_mail++;
 					} else if (!strcasecmp(var, "vm-keep-local-after-email")) {
@@ -2933,12 +2933,12 @@
 		}
 	}
 
-	if (!zstr(vm_storage_dir)) {
-		dir_path = switch_core_session_sprintf(session, "%s%s%s", vm_storage_dir, SWITCH_PATH_SEPARATOR, id);
-	} else if (!zstr(profile->storage_dir)) {
-		dir_path = switch_core_session_sprintf(session, "%s%s%s%s%s", profile->storage_dir, SWITCH_PATH_SEPARATOR, domain_name, SWITCH_PATH_SEPARATOR, id);
+	if (!zstr(vm_voicemail_dir)) {
+		dir_path = switch_core_session_sprintf(session, "%s%s%s", vm_voicemail_dir, SWITCH_PATH_SEPARATOR, id);
+	} else if (!zstr(profile->voicemail_dir)) {
+		dir_path = switch_core_session_sprintf(session, "%s%s%s%s%s", profile->voicemail_dir, SWITCH_PATH_SEPARATOR, domain_name, SWITCH_PATH_SEPARATOR, id);
 	} else {
-		dir_path = switch_core_session_sprintf(session, "%s%svoicemail%s%s%s%s%s%s", SWITCH_GLOBAL_dirs.storage_dir,
+		dir_path = switch_core_session_sprintf(session, "%s%s%s%s%s%s%s%s", SWITCH_GLOBAL_dirs.voicemail_dir,
 											   SWITCH_PATH_SEPARATOR,
 											   SWITCH_PATH_SEPARATOR, profile->name, SWITCH_PATH_SEPARATOR, domain_name, SWITCH_PATH_SEPARATOR, id);
 	}
