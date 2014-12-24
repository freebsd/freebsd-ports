--- log.c.orig	2007-10-25 14:03:31.000000000 +0800
+++ log.c	2014-12-05 15:11:31.000000000 +0800
@@ -22,14 +22,15 @@
 #include <stdlib.h>
 #include <string.h>
 #include <syslog.h>
+#include <time.h>
 
 void	log_init(int);
 void	log_warn(const char *, ...);
 void	log_warnx(const char *, ...);
 void	log_info(const char *, ...);
 void	log_debug(const char *, ...);
-__dead void fatal(const char *);
-__dead void fatalx(const char *);
+__dead2 void fatal(const char *);
+__dead2 void fatalx(const char *);
 
 int	 debug;
 
