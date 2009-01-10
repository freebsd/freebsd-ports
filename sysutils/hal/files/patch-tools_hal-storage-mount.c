--- tools/hal-storage-mount.c.orig	2008-05-07 19:24:23.000000000 -0400
+++ tools/hal-storage-mount.c	2008-10-09 00:54:34.000000000 -0400
@@ -56,8 +56,9 @@
 
 #ifdef __FreeBSD__
 #define MOUNT		"/sbin/mount"
-#define MOUNT_OPTIONS	"noexec,nosuid"
+#define MOUNT_OPTIONS	"nosuid"
 #define MOUNT_TYPE_OPT	"-t"
+#define FUSE_DB		"/tmp/.fuse-mnts"
 #elif sun
 #define MOUNT		"/sbin/mount"
 #define MOUNT_OPTIONS	"noexec,nosuid"
@@ -255,6 +256,51 @@ out:
 	return f;
 }
 
+#ifdef __FreeBSD__
+static char *
+resolve_fuse (const char *special)
+{
+	gchar *contents;
+	gchar **lines;
+	gsize len;
+	int i;
+
+	if (! g_file_get_contents (FUSE_DB, &contents, &len, NULL))
+		return g_strdup (special);
+
+	lines = g_strsplit (contents, "\n", 0);
+	g_free (contents);
+
+	for (i = 0; lines && lines[i]; i++) {
+		gchar **fields;
+
+		fields = g_strsplit (lines[i], "=", 2);
+		if (fields && g_strv_length (fields) == 2) {
+			if (strcmp (fields[0], special) == 0) {
+				g_strfreev (fields);
+				g_strfreev (lines);
+				return g_strdup (fields[1]);
+			}
+		}
+		g_strfreev (fields);
+	}
+
+	g_strfreev (lines);
+
+	return g_strdup (special);
+}
+#endif
+
+static char *
+resolve_special (const char *special)
+{
+#ifdef __FreeBSD__
+	if (strstr(special, "fuse"))
+		return resolve_fuse (special);
+#endif
+	return g_strdup (special);
+}
+
 static LibHalVolume *
 volume_findby (LibHalContext *hal_ctx, const char *property, const char *value)
 {
@@ -400,18 +446,20 @@ device_is_mounted (const char *device, c
 		unknown_error ("Cannot open /etc/mtab or equivalent");		
 	}
 	while (((entry = mtab_next (handle, mount_point)) != NULL) && (ret == FALSE)) {
-		char *resolved;
+		char *resolved, *rspecial;
 
 		resolved = resolve_symlink (entry);
+		rspecial = resolve_special (resolved);
+		g_free (resolved);
 #ifdef DEBUG
-		printf ("/proc/mounts: device %s -> %s \n", entry, resolved);
+		printf ("/proc/mounts: device %s -> %s \n", entry, rspecial);
 #endif
-		if (strcmp (device, resolved) == 0) {
-			printf ("%s (-> %s) found in mount list. Not mounting.\n", entry, resolved);
+		if (strcmp (device, rspecial) == 0) {
+			printf ("%s (-> %s) found in mount list. Not mounting.\n", entry, rspecial);
 			ret = TRUE;
 		}
 
-		g_free (resolved);
+		g_free (rspecial);
 	}
 	mtab_close (handle);
 	return ret;
