--- libfwupdplugin/fu-common-freebsd.c.orig	2025-09-12 09:55:19 UTC
+++ libfwupdplugin/fu-common-freebsd.c
@@ -14,6 +14,7 @@
 
 #include "fu-common-private.h"
 #include "fu-kenv.h"
+#include "fu-path.h"
 
 /* bsdisks doesn't provide Manager object */
 #define UDISKS_DBUS_PATH	      "/org/freedesktop/UDisks2"
@@ -122,9 +123,45 @@ fu_common_get_olson_timezone_id_impl(GError **error)
 gchar *
 fu_common_get_olson_timezone_id_impl(GError **error)
 {
+	g_autofree gchar *fn_localtime = fu_path_from_kind(FU_PATH_KIND_LOCALTIME);
+	g_autoptr(GFile) file_localtime = g_file_new_for_path(fn_localtime);
+
+	/* use the last two sections of the symlink target */
+	g_debug("looking for timezone file %s", fn_localtime);
+	if (g_file_query_file_type(file_localtime, G_FILE_QUERY_INFO_NOFOLLOW_SYMLINKS, NULL) ==
+	    G_FILE_TYPE_SYMBOLIC_LINK) {
+		const gchar *target;
+		g_autoptr(GFileInfo) info = NULL;
+
+		info = g_file_query_info(file_localtime,
+					 G_FILE_ATTRIBUTE_STANDARD_SYMLINK_TARGET,
+					 G_FILE_QUERY_INFO_NOFOLLOW_SYMLINKS,
+					 NULL,
+					 error);
+		if (info == NULL)
+			return NULL;
+		target = g_file_info_get_symlink_target(info);
+		if (target != NULL) {
+			g_auto(GStrv) sections = g_strsplit(target, "/", -1);
+			guint sections_len = g_strv_length(sections);
+			if (sections_len < 2) {
+				g_set_error(error,
+					    FWUPD_ERROR,
+					    FWUPD_ERROR_NOT_SUPPORTED,
+					    "invalid symlink target: %s",
+					    target);
+				return NULL;
+			}
+			return g_strdup_printf("%s/%s",
+					       sections[sections_len - 2],
+					       sections[sections_len - 1]);
+		}
+	}
+
+	/* failed */
 	g_set_error_literal(error,
 			    FWUPD_ERROR,
 			    FWUPD_ERROR_NOT_SUPPORTED,
-			    "getting the Olson timezone ID is not supported on FreeBSD");
+			    "no timezone or localtime is available");
 	return NULL;
 }
