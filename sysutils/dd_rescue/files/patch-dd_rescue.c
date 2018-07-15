--- dd_rescue.c.orig	2017-11-02 11:28:14 UTC
+++ dd_rescue.c
@@ -117,6 +117,7 @@
 #include "list.h"
 #include "fmt_no.h"
 #include "find_nonzero.h"
+#include "ffs.h"
 
 #include "fstrim.h"
 
@@ -2712,7 +2713,9 @@ int is_filename(char* arg)
 
 const char* retstrdupcat3(const char* dir, char dirsep, const char* inm)
 {
-	char* ibase = basename(strdupa(inm));
+	char* str = alloca(strlen(inm) + 1);
+	strcpy(str, inm);
+	char* ibase = basename(str);
 	const int dlen = strlen(dir) + (dirsep>0? 1: dirsep);
 	char* ret = (char*)malloc(dlen + strlen(inm) + 1);
 	strcpy(ret, dir);
@@ -2731,7 +2734,9 @@ const char* dirappfile(const char* onm, 
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
