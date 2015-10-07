This code is linux specific. Disable it so users don't get warnings like this:

** (mate-power-backlight-helper:82740): WARNING **: failed to find any devices:
 Error opening directory '/sys/class/backlight': No such file or directory

--- src/gpm-backlight-helper.c.orig	2015-07-22 11:33:09.058354000 +0200
+++ src/gpm-backlight-helper.c	2015-07-22 11:34:39.476169000 +0200
@@ -145,6 +145,10 @@ out:
 gint
 main (gint argc, gchar *argv[])
 {
+#ifdef __FreeBSD__
+	return GCM_BACKLIGHT_HELPER_EXIT_CODE_FAILED;
+#endif
+
 	GOptionContext *context;
 	gint uid;
 	gint euid;
