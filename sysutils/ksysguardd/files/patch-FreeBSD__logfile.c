--- FreeBSD/logfile.c	2011-03-17 20:50:04.000000000 +0200
+++ FreeBSD/logfile.c	2011-01-30 10:24:23.000000000 +0200
@@ -79,8 +79,6 @@
 {
 	char line[1024];
 	unsigned long id;
-	int i;
-	char ch;
 	LogFileEntry *entry;
 
 	sscanf(cmd, "%*s %lu", &id);
