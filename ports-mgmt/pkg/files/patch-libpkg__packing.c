--- libpkg/packing.c.orig	2013-10-05 19:46:59.920058519 +0200
+++ libpkg/packing.c	2013-10-05 19:49:46.531103495 +0200
@@ -36,6 +36,8 @@
 #include <string.h>
 #include <sys/mman.h>
 #include <limits.h>
+#include <pwd.h>
+#include <grp.h>
 
 #include "pkg.h"
 #include "private/event.h"
@@ -44,6 +46,7 @@
 static const char *packing_set_format(struct archive *a, pkg_formats format);
 
 struct packing {
+	bool pass;
 	struct archive *aread;
 	struct archive *awrite;
 	struct archive_entry_linkresolver *resolver;
@@ -67,6 +70,7 @@
 	archive_read_disk_set_symlink_physical((*pack)->aread);
 
 	if (!is_dir(path)) {
+		(*pack)->pass = false;
 		(*pack)->awrite = archive_write_new();
 		archive_write_set_format_pax_restricted((*pack)->awrite);
 		ext = packing_set_format((*pack)->awrite, format);
@@ -89,6 +93,7 @@
 			return EPKG_FATAL;
 		}
 	} else { /* pass mode directly write to the disk */
+		(*pack)->pass = true;
 		(*pack)->awrite = archive_write_disk_new();
 		archive_write_disk_set_options((*pack)->awrite,
 		    EXTRACT_ARCHIVE_FLAGS);
@@ -177,11 +182,21 @@
 		archive_entry_set_size(entry, 0);
 	}
 
-	if (uname != NULL && uname[0] != '\0')
+	if (uname != NULL && uname[0] != '\0') {
+		if (pack->pass) {
+			struct passwd *pw = getpwnam(uname);
+			archive_entry_set_uid(entry, pw->pw_uid);
+		}
 		archive_entry_set_uname(entry, uname);
+	}
 
-	if (gname != NULL && gname[0] != '\0')
+	if (gname != NULL && gname[0] != '\0') {
+		if (pack->pass) {
+			struct group *gr = getgrnam(gname);
+			archive_entry_set_gid(entry, gr->gr_gid);
+		}
 		archive_entry_set_gname(entry, gname);
+	}
 
 	if (perm != 0)
 		archive_entry_set_perm(entry, perm);
