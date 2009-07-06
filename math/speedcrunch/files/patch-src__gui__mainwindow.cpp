--- ./src/gui/mainwindow.cpp.orig	2008-05-23 01:45:21.000000000 +0400
+++ ./src/gui/mainwindow.cpp	2009-07-06 22:50:48.000000000 +0400
@@ -37,7 +37,6 @@
 #include "tipwidget.hxx"
 #include "variablesdock.hxx"
 
-#include "3rdparty/util/binreloc.h"
 #include "base/constants.hxx"
 #include "base/evaluator.hxx"
 #include "base/functions.hxx"
@@ -340,17 +339,7 @@
   translator->load( fname );
   return translator;
 #else
-
-  BrInitError error;
-  if ( br_init( & error ) == 0 && error != BR_INIT_ERROR_DISABLED )
-  {
-      qDebug( "Warning: BinReloc failed to initialize (error code %d)", error );
-      qDebug( "Will fallback to hardcoded default path." );
-  }
-
-  char * dataDir = br_find_data_dir( 0 );
-  QString localeDir = QString( dataDir ) + "/speedcrunch/locale";
-  free( dataDir );
+  QString localeDir = "%%PREFIX%%/share/speedcrunch/locale";
   if ( translator->load( localeFile, localeDir ) )
     return translator;
   else
@@ -1004,16 +993,7 @@
       appPath.remove( ii, appPath.length() );
   booksDir = appPath + '/' + QString( "books/" );
 #else
-  BrInitError error;
-  if ( br_init( & error ) == 0 && error != BR_INIT_ERROR_DISABLED )
-  {
-      qDebug( "Warning: BinReloc failed to initialize (error code %d)", error );
-      qDebug( "Will fallback to hardcoded default path." );
-  }
-
-  char * dataDir = br_find_data_dir( 0 );
-  booksDir = QString( dataDir ) + "/speedcrunch/books/";
-  free( dataDir );
+  booksDir = "%%PREFIX%%/share/speedcrunch/books/";
 #endif
 
   docks.book = new BookDock( booksDir, "math_index.html", settings.language,
