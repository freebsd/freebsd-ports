--- dd_rescue.c.orig	2023-02-23 21:51:27 UTC
+++ dd_rescue.c
@@ -116,6 +116,7 @@
 #include "list.h"
 #include "fmt_no.h"
 #include "find_nonzero.h"
+#include "ffs.h"
 
 #include "fstrim.h"
 
@@ -2730,7 +2731,9 @@ const char* retstrdupcat3(const char* dir, char dirsep
 
 const char* retstrdupcat3(const char* dir, char dirsep, const char* inm)
 {
-	char* ibase = basename(strdupa(inm));
+	char* str = alloca(strlen(inm) + 1);
+	strcpy(str, inm);
+	char* ibase = basename(str);
 	const int dlen = strlen(dir) + (dirsep>0? 1: dirsep);
 	char* ret = (char*)malloc(dlen + strlen(inm) + 1);
 	strcpy(ret, dir);
@@ -2749,7 +2752,9 @@ const char* dirappfile(const char* onm, opt_t *op)
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
