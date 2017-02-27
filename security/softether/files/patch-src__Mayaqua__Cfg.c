--- src/Mayaqua/Cfg.c.orig	2016-05-03 06:16:53 UTC
+++ src/Mayaqua/Cfg.c
@@ -139,7 +139,7 @@ void BackupCfgWEx(CFG_RW *rw, FOLDER *f,
 	}
 
 	// Determine the directory name
-	UniFormat(dirname, sizeof(dirname), L"@backup.%s", original[0] == L'@' ? original + 1 : original);
+	UniFormat(dirname, sizeof(dirname), L"/var/db/softether/backup.%s", original[0] == L'@' ? original + 1 : original);
 
 	// Determine the file name
 	LocalTime(&st);
