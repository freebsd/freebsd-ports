--- srclib/apr-util/build/dbm.m4.orig	Wed Nov 17 02:12:20 2004
+++ srclib/apr-util/build/dbm.m4	Mon Jan 17 21:22:47 2005
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
-    "db-4.1 db41 db4 db"
+    "db41/dh.h",
+    "db-41"
   )
   if test "$apu_have_db" = "1"; then
     apu_db_version=4
@@ -403,8 +403,8 @@
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
@@ -422,8 +422,8 @@
   fi
   APU_CHECK_BERKELEY_DB("4", "3", "-1",
     "$places",
-    "db43/db.h db4/db.h db.h",
-    "db-4.3 db43 db4 db"
+    "db43/db.h",
+    "db-4.3"
   )
   if test "$apu_have_db" = "1"; then
     apu_db_version=4
