Index: aclocal.m4
diff -u aclocal.m4.orig aclocal.m4
--- aclocal.m4.orig	Thu Mar 20 04:04:34 2003
+++ aclocal.m4	Fri Mar 21 20:09:38 2003
@@ -453,7 +453,7 @@
 	    BDB_LIBADD=""
 	fi
 
-        for dbname in db-4.1 db4.1 db-4.0 db4.0 db-4 db4 db-3.3 db3.3 db-3.2 db3.2 db-3.1 db3.1 db-3 db3 db
+        for dbname in db-4.1 db4.1 db-4.0 db4.0 db-4 db-3.3 db3.3 db-3.2 db3.2 db-3.1 db3.1 db-3 db3 db
           do
             AC_CHECK_LIB($dbname, db_create, BDB_LIBADD="$BDB_LIBADD -l$dbname";
               dblib="berkeley"; break, dblib="no")
@@ -1574,7 +1574,7 @@
   LIB_UCDSNMP=""
   if test "$with_ucdsnmp" != no; then
     AC_DEFINE(HAVE_UCDSNMP)
-    LIB_UCDSNMP="-lucdagent -lucdmibs -lsnmp"
+    LIB_UCDSNMP="-lucdagent -lucdmibs -lsnmp -lkvm"
     AC_CHECK_LIB(rpm, rpmdbOpen,
 		 LIB_UCDSNMP="${LIB_UCDSNMP} -lrpm -lpopt",,-lpopt)
   fi
