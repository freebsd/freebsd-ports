error: invalid suffix on literal; C++11 requires a space between literal and identifier
  [-Wreserved-user-defined-literal]
     fileSearchPaths << file.fileName().section( "/", 0, -5, 
     QString::SectionIncludeTrailingSep ) + QLatin1String( "lib"SOPRANO_LIB_SUFFIX );
                                                                                                                           ^

--- soprano/pluginmanager.cpp.orig	2013-10-09 17:22:28 UTC
+++ soprano/pluginmanager.cpp
@@ -43,7 +43,7 @@ namespace {
         fileSearchPaths << file.fileName().section( '/', 0, -2 );
 #ifndef Q_OS_WIN
         // the lib folder in the same prefix
-        fileSearchPaths << file.fileName().section( "/", 0, -5, QString::SectionIncludeTrailingSep ) + QLatin1String( "lib"SOPRANO_LIB_SUFFIX );
+        fileSearchPaths << file.fileName().section( "/", 0, -5, QString::SectionIncludeTrailingSep ) + QLatin1String( "lib" SOPRANO_LIB_SUFFIX );
 #endif
         return Soprano::findLibraryPath( file.library(), fileSearchPaths, QStringList() << QLatin1String( "soprano" ) );
     }
