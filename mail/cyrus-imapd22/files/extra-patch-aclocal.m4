Index: aclocal.m4
diff -u aclocal.m4.orig aclocal.m4
--- aclocal.m4.orig	Thu Jul 17 06:20:37 2003
+++ aclocal.m4	Fri Jul 18 00:58:34 2003
@@ -489,7 +489,7 @@
 	    BDB_LIBADD=""
 	fi
 
-        for dbname in db-4.1 db4.1 db41 db-4.0 db4.0 db-4 db40 db4 db-3.3 db3.3 db33 db-3.2 db3.2 db32 db-3.1 db3.1 db31 db-3 db30 db3 db
+        for dbname in ${with_bdb} db-4.1 db4.1 db41 db-4.0 db4.0 db-4 db40 db4 db-3.3 db3.3 db33 db-3.2 db3.2 db32 db-3.1 db3.1 db31 db-3 db30 db3 db
           do
             AC_CHECK_LIB($dbname, db_create, BDB_LIBADD="$BDB_LIBADD -l$dbname";
               dblib="berkeley"; break, dblib="no")
@@ -1629,7 +1629,7 @@
   LIB_UCDSNMP=""
   if test "$with_ucdsnmp" != no; then
     AC_DEFINE(HAVE_UCDSNMP)
-    LIB_UCDSNMP="-lucdagent -lucdmibs -lsnmp"
+    LIB_UCDSNMP="-lucdagent -lucdmibs -lsnmp -lkvm"
     AC_CHECK_LIB(rpm, rpmdbOpen,
 		 LIB_UCDSNMP="${LIB_UCDSNMP} -lrpm -lpopt",,-lpopt)
   fi
