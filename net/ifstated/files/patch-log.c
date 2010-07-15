--- log.c.orig	2010-06-11 13:29:09.127347360 -0500
+++ log.c	2010-06-11 13:29:20.636464838 -0500
@@ -28,8 +28,8 @@
 void	log_warnx(const char *, ...);
 void	log_info(const char *, ...);
 void	log_debug(const char *, ...);
-__dead void fatal(const char *);
-__dead void fatalx(const char *);
+__dead2 void fatal(const char *);
+__dead2 void fatalx(const char *);
 
 int	 debug;
 
