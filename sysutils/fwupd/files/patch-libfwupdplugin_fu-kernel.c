--- libfwupdplugin/fu-kernel.c.orig	2026-07-27 15:39:53 UTC
+++ libfwupdplugin/fu-kernel.c
@@ -343,6 +343,9 @@ fu_kernel_get_cmdline(GError **error)
 	if (!g_file_get_contents("/proc/cmdline", &buf, &bufsz, error))
 		return NULL;
 	return fu_kernel_parse_cmdline(buf, bufsz);
+#elif defined(__FreeBSD__)
+	// XXX: there is no /proc/cmdline equivalent
+	return fu_kernel_parse_cmdline("", 0);
 #else
 	g_set_error_literal(error,
 			    FWUPD_ERROR,
