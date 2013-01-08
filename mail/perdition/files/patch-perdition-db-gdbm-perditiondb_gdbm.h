--- ./perdition/db/gdbm/perditiondb_gdbm.h.orig	2013-01-08 16:05:30.000000000 -0500
+++ ./perdition/db/gdbm/perditiondb_gdbm.h	2013-01-08 16:05:40.000000000 -0500
@@ -31,7 +31,6 @@
 #include <gdbm.h>
 
 extern gdbm_error gdbm_errno;
-extern char *gdbm_version;
 
 #ifndef PERDITIONDB_GDBM_SYSCONFDIR
 #define PERDITIONDB_GDBM_SYSCONFDIR "/usr/local/etc/perdition"
