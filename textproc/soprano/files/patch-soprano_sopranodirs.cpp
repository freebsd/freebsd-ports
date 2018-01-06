error: invalid suffix on literal; C++11 requires a space between literal and identifier
    paths << QLatin1String( SOPRANO_PREFIX"/lib"SOPRANO_LIB_SUFFIX );
                                                ^
--- soprano/sopranodirs.cpp.orig	2018-01-06 22:23:48 UTC
+++ soprano/sopranodirs.cpp
@@ -124,14 +124,14 @@ QStringList Soprano::envDirList( const char* var )
 QStringList Soprano::libDirs()
 {
     QStringList paths = QCoreApplication::libraryPaths();
-    paths << QLatin1String( SOPRANO_PREFIX"/lib"SOPRANO_LIB_SUFFIX );
+    paths << QLatin1String( SOPRANO_PREFIX "/lib" SOPRANO_LIB_SUFFIX );
 #ifdef Q_OS_WIN
-    paths << QLatin1String( SOPRANO_PREFIX"/bin" );
+    paths << QLatin1String( SOPRANO_PREFIX "/bin" );
     paths << getWinPrefix() + QLatin1String( "/bin" );
-    paths << getWinPrefix() + QLatin1String( "/lib"SOPRANO_LIB_SUFFIX );
+    paths << getWinPrefix() + QLatin1String( "/lib" SOPRANO_LIB_SUFFIX );
 #else
-    paths << QLatin1String( "/usr/lib"SOPRANO_LIB_SUFFIX );
-    paths << QLatin1String( "/usr/local/lib"SOPRANO_LIB_SUFFIX );
+    paths << QLatin1String( "/usr/lib" SOPRANO_LIB_SUFFIX );
+    paths << QLatin1String( "/usr/local/lib" SOPRANO_LIB_SUFFIX );
     paths += Soprano::envDirList( "LD_LIBRARY_PATH" );
 #endif
     return paths;
