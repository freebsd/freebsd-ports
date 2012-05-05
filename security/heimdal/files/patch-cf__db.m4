--- cf/db.m4.orig	2012-03-22 10:24:19.000000000 +0100
+++ cf/db.m4	2012-03-22 10:27:20.000000000 +0100
@@ -42,6 +42,7 @@
 	           db4/db.h				\
 	           db3/db.h				\
 	           db.h					\
+	           db_185.h				\
     ])])
 
 dnl db_create is used by db3 and db4 and db5
@@ -77,6 +78,8 @@
   #include <stdio.h>
   #if defined(HAVE_DB2_DB_H)
   #include <db2/db.h>
+  #elif defined(HAVE_DB_185_H)
+  #include <db_185.h>
   #elif defined(HAVE_DB_H)
   #include <db.h>
   #else
