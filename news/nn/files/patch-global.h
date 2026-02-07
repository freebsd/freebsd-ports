--- global.h.orig	2005-04-01 05:39:01 UTC
+++ global.h
@@ -258,7 +258,7 @@ int             nn_truncate(char *, off_
 char           *strsave(char *);
 char           *str3save(char *, char *, char *);
 char           *fgetstr(FILE *);
-int             getline(char *, int);
+int             get_line(char *, int);
 extern char    *tmp_directory;
 extern char    *nntp_cache_dir;
 #endif				/* _NN_GLOBAL_H */
