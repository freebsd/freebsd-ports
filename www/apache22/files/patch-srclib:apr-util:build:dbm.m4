--- srclib/apr-util/build/dbm.m4.orig	2008-05-28 16:27:01.000000000 +0000
+++ srclib/apr-util/build/dbm.m4	2008-07-11 20:32:59.000000000 +0000
@@ -315,8 +315,8 @@
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
@@ -358,7 +358,7 @@
   APU_CHECK_BERKELEY_DB(3, -1, -1,
     "$places",
     "db3/db.h db.h",
-    "db3 db"
+    "db3"
   )
   if test "$apu_have_db" = "1"; then
     apu_db_version=3
@@ -378,8 +378,8 @@
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
@@ -399,8 +399,8 @@
   fi
   APU_CHECK_BERKELEY_DB("4", "1", "-1",
     "$places",
-    "db41/db.h db4/db.h db.h",
-    "db-4.1 db41 db4 db"
+    "db41/db.h",
+    "db41"
   )
   if test "$apu_have_db" = "1"; then
     apu_db_version=4
@@ -420,8 +420,8 @@
   fi
   APU_CHECK_BERKELEY_DB("4", "2", "-1",
     "$places",
-    "db42/db.h db4/db.h db.h",
-    "db-4.2 db42 db4 db"
+    "db42/db.h",
+    "db-4.2"
   )
   if test "$apu_have_db" = "1"; then
     apu_db_version=4
@@ -439,8 +439,8 @@
   fi
   APU_CHECK_BERKELEY_DB("4", "3", "-1",
     "$places",
-    "db43/db.h db4/db.h db.h",
-    "db-4.3 db4-4.3 db43 db4 db"
+    "db43/db.h",
+    "db-4.3"
   )
   if test "$apu_have_db" = "1"; then
     apu_db_version=4
@@ -503,6 +503,25 @@
     apu_db_version=4
   fi
 ])
+dnl
+dnl APU_CHECK_DB47: is DB4.7 present?
+dnl
+dnl if present: sets apu_db_header, apu_db_lib, and apu_db_version
+dnl
+AC_DEFUN([APU_CHECK_DB47], [
+  places=$1
+  if test -z "$places"; then
+    places="std /usr/local/BerkeleyDB.4.7 /boot/home/config"
+  fi
+  APU_CHECK_BERKELEY_DB("4", "7", "-1",
+    "$places",
+    "db47/db.h db4/db.h db.h",
+    "db-4.7 db4-4.7 db47 db4 db"
+  )
+  if test "$apu_have_db" = "1"; then
+    apu_db_version=4
+  fi
+])
 
 AC_DEFUN([APU_CHECK_DB], [
   requested=$1
@@ -581,6 +600,12 @@
       AC_MSG_ERROR(Berkeley db4 not found)
     fi
     ;;
+  db47)
+    APU_CHECK_DB47("$check_places")
+    if test "$apu_db_version" != "4"; then
+      AC_MSG_ERROR(Berkeley db4 not found)
+    fi
+    ;;
   default)
     APU_CHECK_DB_ALL("$check_places")
     ;;
@@ -588,32 +613,35 @@
 ])
 
 dnl
-dnl APU_CHECK_DB_ALL: Try all Berkeley DB versions, from 4.6 to 1.
+dnl APU_CHECK_DB_ALL: Try all Berkeley DB versions, from 4.7 to 1.
 dnl
 AC_DEFUN([APU_CHECK_DB_ALL], [
   all_places=$1
  
-  APU_CHECK_DB46("$all_places")
+  APU_CHECK_DB47("$all_places")
   if test "$apu_db_version" != "4"; then
-    APU_CHECK_DB45("$all_places")
+    APU_CHECK_DB46("$all_places")
     if test "$apu_db_version" != "4"; then
-      APU_CHECK_DB44("$all_places")
+      APU_CHECK_DB45("$all_places")
       if test "$apu_db_version" != "4"; then
-        APU_CHECK_DB43("$all_places")
+        APU_CHECK_DB44("$all_places")
         if test "$apu_db_version" != "4"; then
-          APU_CHECK_DB42("$all_places")
+          APU_CHECK_DB43("$all_places")
           if test "$apu_db_version" != "4"; then
-            APU_CHECK_DB41("$all_places")
+            APU_CHECK_DB42("$all_places")
             if test "$apu_db_version" != "4"; then
-              APU_CHECK_DB4("$all_places")
+              APU_CHECK_DB41("$all_places")
               if test "$apu_db_version" != "4"; then
-                APU_CHECK_DB3("$all_places")
-                if test "$apu_db_version" != "3"; then
-                  APU_CHECK_DB2("$all_places")
-                  if test "$apu_db_version" != "2"; then
-                    APU_CHECK_DB1("$all_places")
-                    if test "$apu_db_version" != "1"; then
-                      APU_CHECK_DB185("$all_places")
+                APU_CHECK_DB4("$all_places")
+                if test "$apu_db_version" != "4"; then
+                  APU_CHECK_DB3("$all_places")
+                  if test "$apu_db_version" != "3"; then
+                    APU_CHECK_DB2("$all_places")
+                    if test "$apu_db_version" != "2"; then
+                      APU_CHECK_DB1("$all_places")
+                      if test "$apu_db_version" != "1"; then
+                        APU_CHECK_DB185("$all_places")
+                      fi
                     fi
                   fi
                 fi
@@ -651,11 +679,11 @@
   apu_db_version=0
 
   AC_ARG_WITH(dbm, [APR_HELP_STRING([--with-dbm=DBM], [choose the DBM type to use.
-      DBM={sdbm,gdbm,ndbm,db,db1,db185,db2,db3,db4,db41,db42,db43,db44,db45,db46}])],
+      DBM={sdbm,gdbm,ndbm,db,db1,db185,db2,db3,db4,db41,db42,db43,db44,db45,db46,db47}])],
   [
     if test "$withval" = "yes"; then
       AC_MSG_ERROR([--with-dbm needs to specify a DBM type to use.
-        One of: sdbm, gdbm, ndbm, db, db1, db185, db2, db3, db4, db41, db42, db43, db44, db45, db46])
+        One of: sdbm, gdbm, ndbm, db, db1, db185, db2, db3, db4, db41, db42, db43, db44, db45, db46, db47])
     fi
     requested="$withval"
   ], [
@@ -850,6 +878,10 @@
       apu_use_db=1
       apu_default_dbm=db4
       ;;
+    db47)
+      apu_use_db=1
+      apu_default_dbm=db4
+      ;;
     default)
       dnl ### use more sophisticated DBMs for the default?
       apu_default_dbm="sdbm (default)"
@@ -857,7 +889,7 @@
       ;;
     *)
       AC_MSG_ERROR([--with-dbm=$look_for is an unknown DBM type.
-        Use one of: sdbm, gdbm, ndbm, db, db1, db185, db2, db3, db4, db41, db42, db43, db44, db45, db46])
+        Use one of: sdbm, gdbm, ndbm, db, db1, db185, db2, db3, db4, db41, db42, db43, db44, db45, db46, db47])
       ;;
   esac
 
