--- sigscheme/src/sigscheme.h.orig	2007-03-15 01:15:06.000000000 +0900
+++ sigscheme/src/sigscheme.h	2007-11-04 18:01:05.000000000 +0900
@@ -1242,6 +1242,7 @@
 SCM_EXPORT void *scm_calloc(size_t number, size_t size);
 SCM_EXPORT void *scm_realloc(void *ptr, size_t size);
 SCM_EXPORT char *scm_strdup(const char *str);
+SCM_EXPORT char *scm_align_str(char *str);
 
 /* storage-gc.c */
 SCM_EXPORT void scm_gc_protect(ScmObj *var);
