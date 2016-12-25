--- libpkg/pkg_add.c.orig	2016-12-25 15:12:01 UTC
+++ libpkg/pkg_add.c
@@ -1344,8 +1344,10 @@ pkg_add_fromdir(struct pkg *pkg, const c
 			}
 			kh_find(hls, hardlinks, st.st_ino, path);
 			if (path != NULL) {
-				if (create_hardlink(pkg, f, path) == EPKG_FATAL)
+				if (create_hardlink(pkg, f, path) == EPKG_FATAL) {
+					close(fd);
 					return (EPKG_FATAL);
+				}
 			} else {
 				if (create_regfile(pkg, f, NULL, NULL, fd, NULL) == EPKG_FATAL) {
 					close(fd);
@@ -1353,6 +1355,7 @@ pkg_add_fromdir(struct pkg *pkg, const c
 				}
 				kh_safe_add(hls, hardlinks, f->path, st.st_ino);
 			}
+			close(fd);
 		} else {
 			pkg_emit_error("Invalid file type");
 			return (EPKG_FATAL);
