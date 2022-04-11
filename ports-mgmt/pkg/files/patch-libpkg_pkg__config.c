--- libpkg/pkg_config.c.orig	2021-11-12 08:57:25 UTC
+++ libpkg/pkg_config.c
@@ -97,13 +97,13 @@ static struct config_entry c[] = {
 	{
 		PKG_STRING,
 		"PKG_DBDIR",
-		"/var/db/pkg",
+		"/var/db/pkg" PKG_SUFFIX,
 		"Where the package databases are stored",
 	},
 	{
 		PKG_STRING,
 		"PKG_CACHEDIR",
-		"/var/cache/pkg",
+		"/var/cache/pkg" PKG_SUFFIX,
 		"Directory containing cache of downloaded packages",
 	},
 	{
@@ -145,7 +145,7 @@ static struct config_entry c[] = {
 	{
 		PKG_ARRAY,
 		"REPOS_DIR",
-		"/etc/pkg/,"PREFIX"/etc/pkg/repos/",
+		"/etc/pkg" PKG_SUFFIX "/," PREFIX "/etc/pkg/repos/",
 		"Location of the repository configuration files"
 	},
 	{
