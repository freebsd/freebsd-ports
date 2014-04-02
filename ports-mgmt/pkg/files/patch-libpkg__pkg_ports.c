--- ./libpkg/pkg_ports.c.orig	2014-03-15 13:15:46.000000000 +0000
+++ ./libpkg/pkg_ports.c	2014-04-01 18:20:02.000000000 +0000
@@ -318,9 +318,14 @@
 		buf = NULL;
 		regular = false;
 
-		if (S_ISREG(st.st_mode))
+		if (S_ISDIR(st.st_mode)) {
+			pkg_emit_error("Plist error, directory listed as a file: %s", line);
+			free_file_attr(a);
+			return (EPKG_FATAL);
+		} else if (S_ISREG(st.st_mode))
 			regular = true;
 
+
 		/* special case for hardlinks */
 		if (st.st_nlink > 1)
 			regular = is_hardlink(p->hardlinks, &st);
