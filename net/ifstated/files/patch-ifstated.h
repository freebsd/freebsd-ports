--- ifstated.h.orig	2010-06-11 12:38:31.150643481 -0500
+++ ifstated.h	2010-06-11 12:38:35.768692647 -0500
@@ -142,5 +142,5 @@
 void	log_warnx(const char *, ...);
 void	log_info(const char *, ...);
 void	log_debug(const char *, ...);
-__dead void fatal(const char *);
-__dead void fatalx(const char *);
+__dead2 void fatal(const char *);
+__dead2 void fatalx(const char *);
