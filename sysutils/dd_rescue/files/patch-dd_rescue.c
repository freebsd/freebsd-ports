--- dd_rescue.c.orig	2014-01-18 19:02:26.000000000 +0900
+++ dd_rescue.c	2014-01-18 19:02:39.000000000 +0900
@@ -1848,7 +1848,9 @@
 
 const char* retstrdupcat3(const char* dir, char dirsep, const char* inm)
 {
-	char* ibase = basename(strdupa(inm));
+	char* str = alloca(strlen(inm) + 1);
+	strcpy(str, inm);
+	char* ibase = basename(str);
 	const int dlen = strlen(dir) + (dirsep>0? 1: dirsep);
 	char* ret = (char*)malloc(dlen + strlen(inm) + 1);
 	strcpy(ret, dir);
@@ -1867,7 +1869,9 @@
 {
 	size_t oln = strlen(onm);
 	if (!strcmp(onm, ".")) {
-		char* ret = strdup(basename(strdupa(iname)));
+		char* str = alloca(strlen(iname) + 1);
+		strcpy(str, iname);
+		char* ret = strdup(basename(str));
 		LISTAPPEND(freenames, ret, charp);
 		return ret;
 	}
