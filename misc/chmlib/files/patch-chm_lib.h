--- src/chm_lib.h.orig	Fri Feb 25 21:26:09 2005
+++ src/chm_lib.h	Fri Feb 25 21:26:57 2005
@@ -78,6 +78,12 @@
     char               path[CHM_MAX_PATHLEN+1];
 };
 
+typedef struct chmUnitInfo chmUnitInfo;
+typedef struct chm_dir {
+  int nentries;
+  char **info;
+} chm_dir;
+
 /* open an ITS archive */
 #ifdef PPC_BSTR
 /* RWE 6/12/2003 */
@@ -133,6 +139,7 @@
                       CHM_ENUMERATOR e,
                       void *context);
 
+chm_dir get_names(struct chmFile *h);
 #ifdef __cplusplus
 }
 #endif


