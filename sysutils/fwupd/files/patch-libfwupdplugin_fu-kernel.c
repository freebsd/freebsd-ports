--- libfwupdplugin/fu-kernel.c.orig	2025-09-12 09:55:19 UTC
+++ libfwupdplugin/fu-kernel.c
@@ -329,6 +329,9 @@ fu_kernel_get_cmdline(GError **error)
 	if (!g_file_get_contents("/proc/cmdline", &buf, &bufsz, error))
 		return NULL;
 	return fu_kernel_parse_cmdline(buf, bufsz);
+#elif defined(__FreeBSD__)
+	// XXX: there is no /proc/cmdline equivalent
+	return fu_kernel_parse_cmdline("", 0);
 #else
 	g_set_error_literal(error,
 			    FWUPD_ERROR,
