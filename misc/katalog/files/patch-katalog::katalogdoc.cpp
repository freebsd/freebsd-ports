--- katalog/katalogdoc.cpp.orig	Sat Oct 18 15:42:13 2003
+++ katalog/katalogdoc.cpp	Sat Oct 18 15:42:25 2003
@@ -155,7 +155,7 @@
 bool KatalogDoc::openDocument(const KURL& url, const char *format /*=0*/)
 {
   if( url.isEmpty() )
-    return;
+    return true;
   QString tmpfile;
   KIO::NetAccess::download( url, tmpfile );
   QIODevice * dev = KFilterDev::deviceForFile( tmpfile, "application/x-bzip2" );
