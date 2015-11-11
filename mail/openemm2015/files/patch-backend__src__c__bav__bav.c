--- backend/src/c/bav/bav.c.orig	2015-10-24 14:59:57 UTC
+++ backend/src/c/bav/bav.c
@@ -28,16 +28,17 @@
 # include	<sys/types.h>
 # include	<regex.h>
 # include	<netinet/in.h>
-# include	"libmilter/mfapi.h"
 # include	"bav.h"
+# include	"libmilter/mfapi.h"
 
-# define	SOCK_PATH		"var/run/bav.sock"
-# define	LOCK_PATH		"var/lock/bav.lock"
-# define	CFGFILE			"var/spool/bav/bav.conf"
+# define	SOCK_PATH		"/var/run/openemm/bav.sock"
+# define	LOCK_PATH		"/var/run/openemm/bav.lock"
+# define	CFGFILE			"/usr/local/openemm2015/var/spool/bav/bav.conf"
 # define	X_AGN			"X-AGNMailloop"
 # define	X_LOOP			"X-AGNLoop"
 # define	LOOP_SET		"set"
 
+# define    bool    int
 
 static const char	*program;
 static const char	*loglevel;
