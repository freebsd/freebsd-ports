Index: aclocal.m4
diff -u aclocal.m4.orig aclocal.m4
--- aclocal.m4.orig	Thu Jan 15 23:36:46 2004
+++ aclocal.m4	Sat Jan 17 22:58:54 2004
@@ -505,7 +505,7 @@
 	    BDB_LIBADD=""
 	fi
 
-        for dbname in db-4.2 db4.2 db42 db-4.1 db4.1 db41 db-4.0 db4.0 db-4 db40 db4 db-3.3 db3.3 db33 db-3.2 db3.2 db32 db-3.1 db3.1 db31 db-3 db30 db3 db
+        for dbname in ${with_bdb} db-4.2 db4.2 db42 db-4.1 db4.1 db41 db-4.0 db4.0 db-4 db40 db4 db-3.3 db3.3 db33 db-3.2 db3.2 db32 db-3.1 db3.1 db31 db-3 db30 db3 db
           do
             AC_CHECK_LIB($dbname, db_create, BDB_LIBADD="$BDB_LIBADD -l$dbname";
               dblib="berkeley"; break, dblib="no")
@@ -547,7 +547,7 @@
 	dnl Note that FreeBSD puts it in a wierd place
         dnl (but they should use with-bdb-incdir)
         AC_CHECK_HEADER(db.h,
-                        CYRUS_BERKELEY_DB_CHK_LIB(),
+                        BDB_LIBADD="$BDB_LIBADD -l$with_bdb"; dblib="berkeley",
                         dblib="no")
 
 	CPPFLAGS=$cmu_save_CPPFLAGS
@@ -1786,7 +1786,7 @@
   LIB_UCDSNMP=""
   if test "$with_ucdsnmp" != no; then
     AC_DEFINE(HAVE_UCDSNMP,1,[Do we have SNMP support?])
-    LIB_UCDSNMP="-lucdagent -lucdmibs -lsnmp"
+    LIB_UCDSNMP="-lucdagent -lucdmibs -lsnmp -lkvm -ldevstat -lwrap"
     AC_CHECK_LIB(rpm, rpmdbOpen,
 		 LIB_UCDSNMP="${LIB_UCDSNMP} -lrpm -lpopt",,-lpopt)
   fi
