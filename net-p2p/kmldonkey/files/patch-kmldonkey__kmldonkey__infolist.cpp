--- ./kmldonkey/kmldonkey/infolist.cpp.orig	2008-07-12 06:05:22.000000000 -0300
+++ ./kmldonkey/kmldonkey/infolist.cpp	2008-07-12 06:06:56.000000000 -0300
@@ -618,6 +618,14 @@
     return i18n( "normal priority", "Normal" );
 }
 
+QString humanReadableFileNumber( int fileNo )
+{
+    QString foo;
+
+    foo = KGlobal::locale()->formatNumber(fileNo, 0);
+
+    return foo;
+}
 
 DownloadFile::DownloadFile( KListView *parent, int file )
     : InfoItem( parent, file )
@@ -712,6 +720,8 @@
         }
         case 13: // filetype
             return KMimeType::findByURL( KURL( "file:/" + it->fileName() ), 0, false, true )->comment();
+        case 14: // number
+            return humanReadableFileNumber(it->fileNo());
 
         default:
             return "ERROR!";
