--- src/Mayaqua/Cfg.c.orig	2014-06-08 06:19:14 UTC
+++ src/Mayaqua/Cfg.c
@@ -124,7 +124,7 @@
 	}
 
 	// Determine the directory name
-	UniFormat(dirname, sizeof(dirname), L"@backup.%s", original[0] == L'@' ? original + 1 : original);
+	UniFormat(dirname, sizeof(dirname), L"/var/db/softether/backup.%s", original[0] == L'@' ? original + 1 : original);
 
 	// Determine the file name
 	LocalTime(&st);
