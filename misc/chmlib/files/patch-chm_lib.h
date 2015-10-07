--- src/chm_lib.h.orig	2009-05-23 14:43:31 UTC
+++ src/chm_lib.h
@@ -82,6 +82,12 @@ struct chmUnitInfo
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
@@ -137,6 +143,7 @@ int chm_enumerate_dir(struct chmFile *h,
                       CHM_ENUMERATOR e,
                       void *context);
 
+chm_dir get_names(struct chmFile *h);
 #ifdef __cplusplus
 }
 #endif
