--- ./src/helpwindow.cpp.orig	Sun Oct  8 08:41:49 2006
+++ ./src/helpwindow.cpp	Sun Jan  7 22:03:39 2007
@@ -172,7 +172,8 @@
   for ( ; it != mHistory.end(); ++it )
     history.append( *it );
 
-  QFile f( QDir::currentDirPath() + "/.history" );
+  // FreeBSD: avoid conflict with editline
+  QFile f( QDir::homeDirPath () + "/.history-digitizer" );
   f.open( IO_WriteOnly );
   QDataStream s( &f );
   s << history;
@@ -183,7 +184,7 @@
   for ( ; it2 != mBookmarks.end(); ++it2 )
     bookmarks.append( *it2 );
 
-  QFile f2( QDir::currentDirPath() + "/.bookmarks" );
+  QFile f2( QDir::homeDirPath () + "/.bookmarks-digitizer" );
   f2.open( IO_WriteOnly );
   QDataStream s2( &f2 );
   s2 << bookmarks;
@@ -295,8 +296,8 @@
 
 void HelpWindow::readHistory()
 {
-  if ( QFile::exists( QDir::currentDirPath() + "/.history" ) ) {
-    QFile f( QDir::currentDirPath() + "/.history" );
+  if ( QFile::exists( QDir::homeDirPath () + "/.history-digitizer" ) ) {
+    QFile f( QDir::homeDirPath () + "/.history-digitizer" );
     f.open( IO_ReadOnly );
     QDataStream s( &f );
     s >> history;
@@ -308,8 +309,8 @@
 
 void HelpWindow::readBookmarks()
 {
-  if ( QFile::exists( QDir::currentDirPath() + "/.bookmarks" ) ) {
-    QFile f( QDir::currentDirPath() + "/.bookmarks" );
+  if ( QFile::exists( QDir::homeDirPath () + "/.bookmarks-digitizer" ) ) {
+    QFile f( QDir::homeDirPath () + "/.bookmarks-digitizer" );
     f.open( IO_ReadOnly );
     QDataStream s( &f );
     s >> bookmarks;
