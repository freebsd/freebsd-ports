--- src/launcher-util.c.orig	2016-05-19 21:36:04 UTC
+++ src/launcher-util.c
@@ -115,3 +115,9 @@ weston_setup_vt_switch_bindings(struct w
 						  switch_vt_binding,
 						  compositor);
 }
+
+int
+weston_launcher_ttyfd(struct weston_launcher *launcher)
+{
+	return 0;
+}
