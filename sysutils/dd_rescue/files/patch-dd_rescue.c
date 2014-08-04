--- dd_rescue.c.orig	2014-05-27 17:27:21.000000000 +0900
+++ dd_rescue.c	2014-06-29 01:17:08.000000000 +0900
@@ -118,6 +118,7 @@
 #include "list.h"
 #include "fmt_no.h"
 #include "find_nonzero.h"
+#include "ffs.h"
 
 #include "fstrim.h"
 
@@ -2304,7 +2305,9 @@
 
 const char* retstrdupcat3(const char* dir, char dirsep, const char* inm)
 {
-	char* ibase = basename(strdupa(inm));
+	char* str = alloca(strlen(inm) + 1);
+	strcpy(str, inm);
+	char* ibase = basename(str);
 	const int dlen = strlen(dir) + (dirsep>0? 1: dirsep);
 	char* ret = (char*)malloc(dlen + strlen(inm) + 1);
 	strcpy(ret, dir);
@@ -2323,7 +2326,9 @@
 {
 	size_t oln = strlen(onm);
 	if (!strcmp(onm, ".")) {
-		char* ret = strdup(basename(strdupa(op->iname)));
+		char* str = alloca(strlen(op->iname) + 1);
+		strcpy(str, op->iname);
+		char* ret = strdup(basename(str));
 		LISTAPPEND(freenames, ret, charp);
 		return ret;
 	}
