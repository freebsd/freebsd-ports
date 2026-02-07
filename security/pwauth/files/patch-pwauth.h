--- pwauth.h.orig	2020-04-11 16:28:30 UTC
+++ pwauth.h
@@ -73,7 +73,7 @@
 
 #ifdef UNIX_LASTLOG
 # define NEED_UID
-# include <utmp.h>
+# include <utmpx.h>
 # ifdef HAVE_LASTLOG_H
 #  include <lastlog.h>
 # endif
