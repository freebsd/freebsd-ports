Index: aclocal.m4
diff -u aclocal.m4.orig aclocal.m4
--- aclocal.m4.orig	Fri Jun 18 03:55:46 2004
+++ aclocal.m4	Wed Jul 21 04:23:48 2004
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
@@ -1806,9 +1806,12 @@
 
     if test -n "$SNMP_LIBS" && test -n "$SNMP_PREFIX"; then
       CPPFLAGS="$CPPFLAGS -I${SNMP_PREFIX}/include"
-      LIB_UCDSNMP=$SNMP_LIBS
+      LIB_UCDSNMP="$SNMP_LIBS -lwrap"
+      PERLLIBDIR=`$PERL -e 'use Config; print "$Config{archlibexp}/CORE";'`
+      LDFLAGS_UCDSNMP="-L${PERLLIBDIR} -R${PERLLIBDIR}"
       AC_DEFINE(HAVE_NETSNMP,1,[Do we have Net-SNMP support?])
       AC_SUBST(LIB_UCDSNMP)
+      AC_SUBST(LDFLAGS_UCDSNMP)
       AC_MSG_RESULT(yes)
     else
       AC_MSG_RESULT(no)
@@ -1834,7 +1837,7 @@
     LIB_UCDSNMP=""
     if test "$with_snmp" != no; then
       AC_DEFINE(HAVE_UCDSNMP,1,[Do we have UCD-SNMP support?])
-      LIB_UCDSNMP="-lucdagent -lucdmibs -lsnmp"
+      LIB_UCDSNMP="-lucdagent -lucdmibs -lsnmp -lkvm -ldevstat -lwrap"
       AC_CHECK_LIB(rpm, rpmdbOpen,
 		 LIB_UCDSNMP="${LIB_UCDSNMP} -lrpm -lpopt",,-lpopt)
     fi
