--- src/edit.c.orig	2026-02-28 20:33:04 UTC
+++ src/edit.c
@@ -154,7 +154,7 @@
     struct ne_lock *lock = NULL;
     char fname[PATH_MAX] = "/tmp/cadaver-edit-XXXXXX";
     const char *pnt;
-    int fd;
+    int fd, sufx_len;
     int is_checkout, is_checkin, can_lock;
     
     uri_path = uri_resolve_native(native_path);
@@ -182,9 +182,11 @@
     if (pnt != NULL && strchr(pnt, '/') == NULL) {
 	strncat(fname, pnt, PATH_MAX-1);
 	fname[PATH_MAX-1] = '\0';
-    }
+	sufx_len = strlen(pnt);
+    } else
+	sufx_len = 0;
 
-    fd = cad_mkstemp(fname);
+    fd = mkstemps(fname, sufx_len);
     if (fd == -1) {
 	printf(_("Could not create temporary file %s:\n%s\n"), fname,
 	       strerror(errno));
