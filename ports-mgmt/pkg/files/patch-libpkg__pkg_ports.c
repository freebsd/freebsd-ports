diff --git libpkg/pkg_ports.c libpkg/pkg_ports.c
index 1c46faa..7bb7bff 100644
--- libpkg/pkg_ports.c
+++ libpkg/pkg_ports.c
@@ -363,6 +363,7 @@ meta_exec(struct plist *p, char *line, bool unexec)
 		    strstr(cmd, "mkfontscale") || strstr(cmd, "mkfontdir") ||
 		    strstr(cmd, "fc-cache") || strstr(cmd, "fonts.dir") ||
 		    strstr(cmd, "fonts.scale") ||
+		    strstr(cmd, "gio-querymodules") ||
 		    strstr(cmd, "gtk-update-icon-cache") ||
 		    strstr(cmd, "update-desktop-database") ||
 		    strstr(cmd, "update-mime-database")) {
