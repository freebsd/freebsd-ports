--- libfwupdplugin/fu-freebsd-efivars.c.orig	2025-09-12 09:55:19 UTC
+++ libfwupdplugin/fu-freebsd-efivars.c
@@ -67,7 +67,7 @@ fu_freebsd_efivars_delete_with_glob(FuEfivars *efivars
 
 	efi_str_to_guid(guid, &guid_to_delete);
 
-	while (efi_get_next_variable_name(&guidt, &name)) {
+	while (efi_get_next_variable_name(&guidt, &name) == 1) {
 		if (memcmp(&guid_to_delete, guidt, sizeof(guid_to_delete)) != 0)
 			continue;
 		if (!g_pattern_match_simple(name, name_glob))
@@ -87,7 +87,7 @@ fu_freebsd_efivars_exists_guid(const gchar *guid)
 	efi_guid_t test;
 
 	efi_str_to_guid(guid, &test);
-	while (efi_get_next_variable_name(&guidt, &name)) {
+	while (efi_get_next_variable_name(&guidt, &name) == 1) {
 		if (memcmp(&test, guidt, sizeof(test)) == 0) {
 			return TRUE;
 		}
@@ -129,7 +129,7 @@ fu_freebsd_efivars_get_names(FuEfivars *efivars, const
 	efi_str_to_guid(guid, &test);
 
 	/* find names with matching GUID */
-	while (efi_get_next_variable_name(&guidt, &name)) {
+	while (efi_get_next_variable_name(&guidt, &name) == 1) {
 		if (memcmp(&test, guidt, sizeof(test)) == 0) {
 			g_ptr_array_add(names, g_strdup(name));
 		}
@@ -156,7 +156,7 @@ fu_freebsd_efivars_space_used(FuEfivars *efivars, GErr
 	efi_guid_t *guidt = NULL;
 	char *name = NULL;
 
-	while (efi_get_next_variable_name(&guidt, &name)) {
+	while (efi_get_next_variable_name(&guidt, &name) == 1) {
 		size_t size = 0;
 		if (efi_get_variable_size(*guidt, name, &size) < 0) {
 			g_set_error_literal(error,
@@ -184,7 +184,7 @@ fu_freebsd_efivars_set_data(FuEfivars *efivars,
 	efi_guid_t guidt;
 	efi_str_to_guid(guid, &guidt);
 
-	if (efi_set_variable(guidt, name, (guint8 *)data, sz, attr) != 0) {
+	if (efi_set_variable(guidt, name, (guint8 *)data, sz, attr, 0644) != 0) {
 		g_set_error(error,
 			    FWUPD_ERROR,
 			    FWUPD_ERROR_NOT_SUPPORTED,
