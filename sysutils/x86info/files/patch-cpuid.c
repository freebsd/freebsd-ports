--- cpuid.c.orig	Wed Aug  9 22:54:05 2006
+++ cpuid.c	Wed Aug  9 22:54:20 2006
@@ -42,7 +42,7 @@
 	fh = open(cpuname, O_RDONLY);
 	if (fh != -1) {
 #ifndef S_SPLINT_S
-		lseek64(fh, (off64_t)idx, SEEK_CUR);
+		lseek(fh, (off_t)idx, SEEK_CUR);
 #endif
 		if (read(fh, &buffer[0], 16) == -1) {
 			perror(cpuname);
