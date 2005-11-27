--- cpuid.c.orig	Sat Nov 26 20:51:01 2005
+++ cpuid.c	Sat Nov 26 20:51:24 2005
@@ -40,7 +40,7 @@
 	snprintf (cpuname,18, "/dev/cpu/%d/cpuid", CPU_number);
 	fh = open (cpuname, O_RDONLY);
 	if (fh != -1) {
-		lseek64 (fh, (off64_t)idx, SEEK_CUR);
+		lseek (fh, (off_t)idx, SEEK_CUR);
 		read (fh, &buffer[0], 16);
 		if (eax!=0)	*eax = (*(unsigned *)(buffer   ));
 		if (ebx!=0)	*ebx = (*(unsigned *)(buffer+ 4));
