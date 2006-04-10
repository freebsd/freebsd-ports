--- ./src/kmldonkey/infolist.cpp.orig	Tue Jul 26 13:40:33 2005
+++ ./src/kmldonkey/infolist.cpp	Sun Apr  9 13:15:40 2006
@@ -491,6 +491,14 @@
     return i18n("normal priority", "Normal");
 }
 
+QString humanReadableFileNumber(int fileNo)
+{
+    QString foo;
+
+    foo = KGlobal::locale()->formatNumber(fileNo, 0);
+
+    return foo;
+}
 
 // DownloadFile
 
@@ -569,6 +577,8 @@
     }
     case 13: // filetype
         return KMimeType::findByURL( KURL( "file:/" + it->fileName() ), 0, false, true)->comment();
+    case 14: // number
+        return humanReadableFileNumber(it->fileNo());
     default:
         return "ERROR!";
     }
