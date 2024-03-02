--- src/tools.c.orig
+++ src/tools.c
@@ -17,9 +17,7 @@
 #endif
 
 #if defined(__FreeBSD__)
-#include <elf.h>
-#include <dlfcn.h>
-extern void *__elf_aux_vector;
+#include <sys/auxv.h>
 #endif
 
 #if defined(__NetBSD__)
@@ -5018,13 +5016,11 @@
 	if (execfn && execfn != ENOENT)
 		ret = (const char *)execfn;
 #elif defined(__FreeBSD__)
-	Elf_Auxinfo *auxv;
-	for (auxv = __elf_aux_vector; auxv->a_type != AT_NULL; ++auxv) {
-		if (auxv->a_type == AT_EXECPATH) {
-			ret = (const char *)auxv->a_un.a_ptr;
-			break;
-		}
-	}
+	static char execpath[MAXPATHLEN];
+	if (execpath[0] == '\0')
+		elf_aux_info(AT_EXECPATH, execpath, MAXPATHLEN);
+	if (execpath[0] != '\0')
+		ret = execpath;
 #elif defined(__NetBSD__)
 	AuxInfo *auxv;
 	for (auxv = _dlauxinfo(); auxv->a_type != AT_NULL; ++auxv) {
