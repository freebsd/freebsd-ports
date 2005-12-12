Index: cmulocal/berkdb.m4
diff -u cmulocal/berkdb.m4.orig cmulocal/berkdb.m4
--- cmulocal/berkdb.m4.orig	Sat Nov 27 06:41:58 2004
+++ cmulocal/berkdb.m4	Sat Dec 10 16:28:44 2005
@@ -212,10 +212,11 @@
 	fi
 
 	saved_LIBS=$LIBS
-        for dbname in db-4.2 db4.2 db42 db-4.1 db4.1 db41 db-4.0 db4.0 db-4 db40 db4 db-3.3 db3.3 db33 db-3.2 db3.2 db32 db-3.1 db3.1 db31 db-3 db30 db3 db
+        for dbname in ${with_bdb} db-4.2 db4.2 db42 db-4.1 db4.1 db41 db-4.0 db4.0 db-4 db40 db4 db-3.3 db3.3 db33 db-3.2 db3.2 db32 db-3.1 db3.1 db31 db-3 db30 db3 db
           do
 	    LIBS="$saved_LIBS -l$dbname"
-	    AC_TRY_LINK([#include <db.h>],
+	    AC_TRY_LINK([#include <stdio.h>
+#include <db.h>],
 	    [db_create(NULL, NULL, 0);],
 	    BDB_LIBADD="$BDB_LIBADD -l$dbname"; dblib="berkeley"; dbname=db,
             dblib="no")
@@ -223,7 +224,8 @@
           done
         if test "$dblib" = "no"; then
 	    LIBS="$saved_LIBS -ldb"
-	    AC_TRY_LINK([#include <db.h>],
+	    AC_TRY_LINK([#include <stdio.h>
+#include <db.h>],
 	    [db_open(NULL, 0, 0, 0, NULL, NULL, NULL);],
 	    BDB_LIBADD="$BDB_LIBADD -ldb"; dblib="berkeley"; dbname=db,
             dblib="no")
