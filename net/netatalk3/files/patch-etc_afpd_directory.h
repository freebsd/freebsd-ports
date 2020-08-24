--- etc/afpd/directory.h.orig	2014-12-11 11:27:44 UTC
+++ etc/afpd/directory.h
@@ -91,7 +91,7 @@ struct maccess {
 #define	AR_UWRITE	(1<<2)
 #define	AR_UOWN		(1<<7)
 
-q_t *invalid_dircache_entries;
+extern q_t *invalid_dircache_entries;
 
 typedef int (*dir_loop)(struct dirent *, char *, void *);
 
