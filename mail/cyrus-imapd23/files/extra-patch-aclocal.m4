Index: aclocal.m4
diff -u aclocal.m4.orig aclocal.m4
--- aclocal.m4.orig	Wed Oct 29 02:24:46 2003
+++ aclocal.m4	Wed Oct 29 04:28:37 2003
@@ -505,7 +505,7 @@
 	    BDB_LIBADD=""
 	fi
 
-        for dbname in db-4.1 db4.1 db41 db-4.0 db4.0 db-4 db40 db4 db-3.3 db3.3 db33 db-3.2 db3.2 db32 db-3.1 db3.1 db31 db-3 db30 db3 db
+        for dbname in ${with_bdb} db-4.1 db4.1 db41 db-4.0 db4.0 db-4 db40 db4 db-3.3 db3.3 db33 db-3.2 db3.2 db32 db-3.1 db3.1 db31 db-3 db30 db3 db
           do
             AC_CHECK_LIB($dbname, db_create, BDB_LIBADD="$BDB_LIBADD -l$dbname";
               dblib="berkeley"; break, dblib="no")
@@ -1664,7 +1664,7 @@
   LIB_UCDSNMP=""
   if test "$with_ucdsnmp" != no; then
     AC_DEFINE(HAVE_UCDSNMP,1,[Do we have SNMP support?])
-    LIB_UCDSNMP="-lucdagent -lucdmibs -lsnmp"
+    LIB_UCDSNMP="-lucdagent -lucdmibs -lsnmp -lkvm"
     AC_CHECK_LIB(rpm, rpmdbOpen,
 		 LIB_UCDSNMP="${LIB_UCDSNMP} -lrpm -lpopt",,-lpopt)
   fi
