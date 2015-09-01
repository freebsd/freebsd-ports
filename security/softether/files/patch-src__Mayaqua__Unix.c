--- src/Mayaqua/Unix.c.orig	2014-06-08 06:19:14 UTC
+++ src/Mayaqua/Unix.c
@@ -916,7 +916,7 @@
 	GetExeDir(dir, sizeof(dir));
 
 	// File name generation
-	Format(name, sizeof(name), "%s/.%s", dir, tmp);
+	Format(name, sizeof(name), "/var/db/softether/.%s", tmp);
 
 	fd = open(name, O_WRONLY);
 	if (fd == -1)
@@ -2254,7 +2254,7 @@
 	Hash(hash, exe_name, StrLen(exe_name), false);
 	BinToStr(tmp1, sizeof(tmp1), hash, sizeof(hash));
 
-	Format(name, size, "%s/.pid_%s", dir, tmp1);
+	Format(name, size, "/var/db/softether/.pid_%s", tmp1);
 }
 
 // Delete the PID file
@@ -2299,7 +2299,7 @@
 	Hash(hash, exe_name, StrLen(exe_name), false);
 	BinToStr(tmp1, sizeof(tmp1), hash, sizeof(hash));
 
-	Format(name, size, "%s/.ctl_%s", dir, tmp1);
+	Format(name, size, "/var/db/softether/.ctl_%s", tmp1);
 }
 
 // Write the CTL file
