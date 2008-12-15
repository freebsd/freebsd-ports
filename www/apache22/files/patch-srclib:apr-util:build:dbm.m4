--- srclib/apr-util/build/dbm.m4.orig	2008-06-25 01:54:26.000000000 +0200
+++ srclib/apr-util/build/dbm.m4	2008-12-09 22:40:21.000000000 +0100
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
@@ -522,6 +522,25 @@
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
@@ -606,6 +625,12 @@
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
@@ -882,6 +907,10 @@
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
