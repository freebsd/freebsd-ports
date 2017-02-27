--- src/Mayaqua/Unix.c.orig	2016-05-03 06:16:53 UTC
+++ src/Mayaqua/Unix.c
@@ -931,7 +931,7 @@ void *UnixNewSingleInstance(char *instan
 	GetExeDir(dir, sizeof(dir));
 
 	// File name generation
-	Format(name, sizeof(name), "%s/.%s", dir, tmp);
+	Format(name, sizeof(name), "/var/db/softether/.%s", tmp);
 
 	fd = open(name, O_WRONLY);
 	if (fd == -1)
@@ -2320,7 +2320,7 @@ void UnixGenPidFileName(char *name, UINT
 	Hash(hash, exe_name, StrLen(exe_name), false);
 	BinToStr(tmp1, sizeof(tmp1), hash, sizeof(hash));
 
-	Format(name, size, "%s/.pid_%s", dir, tmp1);
+	Format(name, size, "/var/db/softether/%s.pid", tmp1);
 }
 
 // Delete the PID file
@@ -2365,7 +2365,7 @@ void UnixGenCtlFileName(char *name, UINT
 	Hash(hash, exe_name, StrLen(exe_name), false);
 	BinToStr(tmp1, sizeof(tmp1), hash, sizeof(hash));
 
-	Format(name, size, "%s/.ctl_%s", dir, tmp1);
+	Format(name, size, "/var/db/softether/.ctl_%s", tmp1);
 }
 
 // Write the CTL file
