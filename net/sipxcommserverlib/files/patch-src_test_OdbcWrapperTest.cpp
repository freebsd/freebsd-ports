--- ./src/test/OdbcWrapperTest.cpp.orig	Sun Jan  7 16:20:24 2007
+++ ./src/test/OdbcWrapperTest.cpp	Sun Jan  7 16:21:01 2007
@@ -54,7 +54,7 @@
          
          CPPUNIT_ASSERT((handle=odbcConnect(DATABASE_NAME,
                                             "localhost",
-                                            "postgres",
+                                            "pgsql",
                                             "{PostgreSQL}"))!=NULL);
          if (handle)
          {                                                     
@@ -141,7 +141,7 @@
        
          CPPUNIT_ASSERT((handle=odbcConnect(DATABASE_NAME,
                                             "localhost",
-                                            "postgres",
+                                            "pgsql",
                                             "{PostgreSQL}"))!=NULL);
          
          if (handle)
@@ -156,7 +156,7 @@
          
          CPPUNIT_ASSERT((handle=odbcConnect(DATABASE_NAME,
                                             "localhost",
-                                            "postgres",
+                                            "pgsql",
                                             "{PostgreSQL}"))!=NULL);
          if (handle)
          {
@@ -173,7 +173,7 @@
       
          CPPUNIT_ASSERT((handle=odbcConnect(DATABASE_NAME,
                                             "localhost",
-                                            "postgres",
+                                            "pgsql",
                                             "{PostgreSQL}"))!=NULL);
          
          if (handle)
@@ -216,7 +216,7 @@
       
          CPPUNIT_ASSERT((handle=odbcConnect(DATABASE_NAME,
                                             "localhost",
-                                            "postgres",
+                                            "pgsql",
                                             "{PostgreSQL}"))!=NULL);
          
          if (handle)
