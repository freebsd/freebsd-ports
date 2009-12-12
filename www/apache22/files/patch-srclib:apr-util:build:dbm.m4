Index: srclib/apr-util/build/dbm.m4
diff -u srclib/apr-util/build/dbm.m4.orig srclib/apr-util/build/dbm.m4
--- srclib/apr-util/build/dbm.m4.orig	2008-11-21 15:32:58.000000000 +0900
+++ srclib/apr-util/build/dbm.m4	2009-12-01 15:02:29.374250645 +0900
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
+dnl APU_CHECK_DB48: is DB4.8 present?
+dnl
+dnl if present: sets apu_db_header, apu_db_lib, and apu_db_version
+dnl
+AC_DEFUN([APU_CHECK_DB48], [
+  places=$1
+  if test -z "$places"; then
+    places="std /usr/local/BerkeleyDB.4.8 /boot/home/config"
+  fi
+  APU_CHECK_BERKELEY_DB("4", "8", "-1",
+    "$places",
+    "db48/db.h db4/db.h db.h",
+    "db-4.8 db4-4.8 db48 db4 db"
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
+  db48)
+    APU_CHECK_DB48("$check_places")
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
+    db48)
+      apu_use_db=1
+      apu_default_dbm=db4
+      ;;
     default)
       dnl ### use more sophisticated DBMs for the default?
       apu_default_dbm="sdbm (default)"
