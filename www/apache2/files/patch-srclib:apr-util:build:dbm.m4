--- srclib/apr-util/build/dbm.m4.orig	Sat Mar 13 05:36:23 2004
+++ srclib/apr-util/build/dbm.m4	Mon Jan 17 18:45:29 2005
@@ -298,8 +298,8 @@
   fi
   APU_CHECK_BERKELEY_DB(1, -1, -1,
     "$places",
-    "db_185.h",
-    "db"
+    "db.h",
+    "c"
   )
   if test "$apu_have_db" = "1"; then
     apu_db_version=185
@@ -341,7 +341,7 @@
   APU_CHECK_BERKELEY_DB(3, -1, -1,
     "$places",
     "db3/db.h db.h",
-    "db3 db"
+    "db3"
   )
   if test "$apu_have_db" = "1"; then
     apu_db_version=3
@@ -361,8 +361,8 @@
   fi
   APU_CHECK_BERKELEY_DB("4", "0", "-1",
     "$places",
-    "db4/db.h db.h",
-    "db-4.0 db4 db"
+    "db4/db.h",
+    "db4"
   )
   if test "$apu_have_db" = "1"; then
     apu_db_version=4
@@ -382,8 +382,8 @@
   fi
   APU_CHECK_BERKELEY_DB("4", "1", "-1",
     "$places",
-    "db41/db.h db4/db.h db.h",
-    "db-4.1 db4 db"
+    "db41/db.h",
+    "db41"
   )
   if test "$apu_have_db" = "1"; then
     apu_db_version=4
@@ -403,8 +403,28 @@
   fi
   APU_CHECK_BERKELEY_DB("4", "2", "-1",
     "$places",
-    "db42/db.h db4/db.h db.h",
-    "db-4.2 db4 db"
+    "db42/db.h",
+    "db-4.2"
+  )
+  if test "$apu_have_db" = "1"; then
+    apu_db_version=4
+  fi
+])
+
+dnl
+dnl APU_CHECK_DB43: is DB4.3 present?
+dnl
+dnl if present: sets apu_db_header, apu_db_lib, and apu_db_version
+dnl
+AC_DEFUN(APU_CHECK_DB43, [
+  places=$1
+  if test -z "$places"; then
+    places="std /usr/local/BerkeleyDB.4.3 /boot/home/config"
+  fi
+  APU_CHECK_BERKELEY_DB("4", "3", "-1",
+    "$places",
+    "db43/db.h",
+    "db-4.3"
   )
   if test "$apu_have_db" = "1"; then
     apu_db_version=4
@@ -465,6 +485,12 @@
       AC_MSG_ERROR(Berkeley db4 not found)
     fi
     ;;
+  db43)
+    APU_CHECK_DB43("$check_places")
+    if test "$apu_db_version" != "4"; then
+      AC_MSG_ERROR(Berkeley db4 not found)
+    fi
+    ;;
   default)
     APU_CHECK_DB_ALL("$check_places")
     ;;
@@ -472,11 +498,12 @@
 ])
 
 dnl
-dnl APU_CHECK_DB_ALL: Try all Berkeley DB versions, from 4.2 to 1.
+dnl APU_CHECK_DB_ALL: Try all Berkeley DB versions, from 4.3 to 1.
 dnl
 AC_DEFUN(APU_CHECK_DB_ALL, [
   all_places=$1
- 
+ APU_CHECK_DB43("$all_places")
+  if test "$apu_db_version" != "4"; then
   APU_CHECK_DB42("$all_places")
   if test "$apu_db_version" != "4"; then
     APU_CHECK_DB41("$all_places")
@@ -496,6 +523,7 @@
       fi
     fi
   fi
+ fi
   AC_MSG_CHECKING(for Berkeley DB)
   if test "$apu_have_db" = "1"; then
     AC_MSG_RESULT(found db$apu_db_version)
@@ -528,7 +556,7 @@
   ], [
     if test "$withval" = "yes"; then
       AC_MSG_ERROR([--with-dbm needs to specify a DBM type to use.
-        One of: sdbm, gdbm, ndbm, db, db1, db185, db2, db3, db4, db41, db42])
+        One of: sdbm, gdbm, ndbm, db, db1, db185, db2, db3, db4, db41, db42,db43])
     fi
     requested="$withval"
   ], [
@@ -703,6 +731,10 @@
       apu_default_dbm=db4
       ;;
     db42)
+      apu_use_db=1
+      apu_default_dbm=db4
+      ;;
+    db43)
       apu_use_db=1
       apu_default_dbm=db4
       ;;
