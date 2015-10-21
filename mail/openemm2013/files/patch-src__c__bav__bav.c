--- src/c/bav/bav.c.orig	2015-10-11 16:41:54 UTC
+++ src/c/bav/bav.c
@@ -26,16 +26,18 @@
 # include	<unistd.h>
 # include	<string.h>
 # include	<netinet/in.h>
+# include       "bav.h"
 # include	"libmilter/mfapi.h"
-# include	"bav.h"
 
-# define	SOCK_PATH		"var/run/bav.sock"
-# define	LOCK_PATH		"var/lock/bav.lock"
-# define	CFGFILE			"var/spool/bav/bav.conf"
+# define	SOCK_PATH		"/var/run/openemm/bav.sock"
+# define	LOCK_PATH		"/var/run/openemm/bav.lock"
+# define	CFGFILE			"/usr/local/openemm2013/var/spool/bav/bav.conf"
 # define	X_AGN			"X-AGNMailloop"
 # define	X_LOOP			"X-AGNLoop"
 # define	LOOP_SET		"set"
 
+# define 	bool	int
+
 static const char	*program;
 static const char	*loglevel;
 static char		*cfgfile;
