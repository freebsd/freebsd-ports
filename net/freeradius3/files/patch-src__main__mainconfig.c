Fix FreeRADIUS 3.0.3 crash
https://github.com/FreeRADIUS/freeradius-server/issues/634
==================================================================
--- ./src/main/mainconfig.c.orig	2014-05-17 11:19:37.000000000 +0200
+++ ./src/main/mainconfig.c	2014-05-17 11:20:09.000000000 +0200
@@ -83,7 +83,7 @@
  */
 static char const	*localstatedir = NULL;
 static char const	*prefix = NULL;
-static char		my_name;
+static char const	*my_name = NULL;
 static char const	*sbindir = NULL;
 static char const	*run_dir = NULL;
 static char		*syslog_facility = NULL;
