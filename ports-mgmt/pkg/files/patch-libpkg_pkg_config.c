--- libpkg/pkg_config.c.orig	2014-07-26 10:02:30.126604570 -0400
+++ libpkg/pkg_config.c	2014-07-26 10:04:08.818597834 -0400
@@ -128,7 +128,7 @@
 	{
 		PKG_ARRAY,
 		"REPOS_DIR",
-		"/etc/pkg/,"PREFIX"/etc/pkg/repos/",
+		PREFIX"/etc/pkg/repos/",
 		"Location of the repository configuration files"
 	},
 	{
