--- srclib/apr-util/build/dbm.m4.orig	Thu Feb 24 10:23:34 2005
+++ srclib/apr-util/build/dbm.m4	Sun Oct 30 19:44:43 2005
@@ -314,8 +314,8 @@
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
@@ -357,7 +357,7 @@
   APU_CHECK_BERKELEY_DB(3, -1, -1,
     "$places",
     "db3/db.h db.h",
-    "db3 db"
+    "db3"
   )
   if test "$apu_have_db" = "1"; then
     apu_db_version=3
@@ -377,8 +377,8 @@
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
@@ -398,8 +398,8 @@
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
@@ -419,8 +419,8 @@
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
@@ -438,8 +438,8 @@
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
