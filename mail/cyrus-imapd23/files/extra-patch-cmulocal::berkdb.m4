Index: cmulocal/berkdb.m4
diff -u cmulocal/berkdb.m4.orig cmulocal/berkdb.m4
--- cmulocal/berkdb.m4.orig	Tue May 23 22:27:15 2006
+++ cmulocal/berkdb.m4	Wed May 24 00:08:16 2006
@@ -213,10 +213,11 @@
 	fi
 
 	saved_LIBS=$LIBS
-        for dbname in db-4.4 db4.4 db44 db-4.3 db4.3 db43 db-4.2 db4.2 db42 db-4.1 db4.1 db41 db-4.0 db4.0 db-4 db40 db4 db-3.3 db3.3 db33 db-3.2 db3.2 db32 db-3.1 db3.1 db31 db-3 db30 db3 db
+        for dbname in ${with_bdb} db-4.4 db4.4 db44 db-4.3 db4.3 db43 db-4.2 db4.2 db42 db-4.1 db4.1 db41 db-4.0 db4.0 db-4 db40 db4 db-3.3 db3.3 db33 db-3.2 db3.2 db32 db-3.1 db3.1 db31 db-3 db30 db3 db
           do
 	    LIBS="$saved_LIBS -l$dbname"
-	    AC_TRY_LINK([#include <db.h>],
+	    AC_TRY_LINK([#include <stdio.h>
+#include <db.h>],
 	    [db_create(NULL, NULL, 0);],
 	    BDB_LIBADD="$BDB_LIBADD -l$dbname"; dblib="berkeley"; dbname=db,
             dblib="no")
@@ -224,7 +225,8 @@
           done
         if test "$dblib" = "no"; then
 	    LIBS="$saved_LIBS -ldb"
-	    AC_TRY_LINK([#include <db.h>],
+	    AC_TRY_LINK([#include <stdio.h>
+#include <db.h>],
 	    [db_open(NULL, 0, 0, 0, NULL, NULL, NULL);],
 	    BDB_LIBADD="$BDB_LIBADD -ldb"; dblib="berkeley"; dbname=db,
             dblib="no")
