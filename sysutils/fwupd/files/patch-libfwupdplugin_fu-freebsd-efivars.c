--- libfwupdplugin/fu-freebsd-efivars.c.orig	2026-03-12 10:08:33 UTC
+++ libfwupdplugin/fu-freebsd-efivars.c
@@ -17,6 +17,7 @@
 
 #include "fu-efivars.h"
 #include "fu-freebsd-efivars.h"
+#include "fu-mem.h"
 
 struct _FuFreebsdEfivars {
 	FuEfivars parent_instance;
@@ -104,8 +105,45 @@ fu_freebsd_efivars_get_data(FuEfivars *efivars,
 			    GError **error)
 {
 	efi_guid_t guidt;
+	guint8 *local_data;
+	gsize local_data_sz;
+	FuEfiVariableAttrs local_attr;
+
 	efi_str_to_guid(guid, &guidt);
-	return (efi_get_variable(guidt, name, data, data_sz, attr) != 0);
+
+	/* native libefivar sets output parameters even on failure */
+	if (efi_get_variable(guidt,
+			     name,
+			     &local_data,
+			     &local_data_sz,
+			     &local_attr) < 0) {
+		g_set_error(error,
+			    FWUPD_ERROR,
+			    FWUPD_ERROR_NOT_FOUND,
+			    "failed to get efivar %s:%s",
+			    guid, name);
+		return FALSE;
+	}
+
+	if (data != NULL) {
+		/* native libefivar uses a static buffer for data */
+		*data = g_malloc(local_data_sz);
+		if (!fu_memcpy_safe(*data,
+				    local_data_sz,
+				    0,
+				    local_data,
+				    local_data_sz,
+				    0,
+				    local_data_sz,
+				    error)) {
+			return FALSE;
+		}
+	}
+	if (data_sz != NULL)
+		*data_sz = local_data_sz;
+	if (attr != NULL)
+		*attr = local_attr;
+	return TRUE;
 }
 
 static gboolean
@@ -182,7 +220,7 @@ fu_freebsd_efivars_set_data(FuEfivars *efivars,
 	efi_guid_t guidt;
 	efi_str_to_guid(guid, &guidt);
 
-	if (efi_set_variable(guidt, name, (guint8 *)data, sz, attr, 0644) != 0) {
+	if (efi_set_variable(guidt, name, (guint8 *)data, sz, attr) < 0) {
 		g_set_error(error,
 			    FWUPD_ERROR,
 			    FWUPD_ERROR_NOT_SUPPORTED,
