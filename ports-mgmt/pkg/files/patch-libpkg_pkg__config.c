--- libpkg/pkg_config.c.orig	2018-01-09 15:56:55 UTC
+++ libpkg/pkg_config.c
@@ -242,7 +242,7 @@ static struct config_entry c[] = {
 	{
 		PKG_INT,
 		"FETCH_TIMEOUT",
-		"30",
+		"180",
 		"Number of seconds before fetch(3) times out",
 	},
 	{
