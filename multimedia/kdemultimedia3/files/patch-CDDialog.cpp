--- kscd/CDDialog.cpp.orig	Fri Nov 24 18:13:01 2000
+++ kscd/CDDialog.cpp	Mon Nov 27 10:22:44 2000
@@ -24,6 +24,7 @@
 
 #include <klocale.h>
 #include <kdebug.h>
+#include <ktempfile.h>
 
 #include <stdio.h>
 #include <math.h>
@@ -427,8 +428,9 @@
   dialog->getSelection(submitcat);
   delete dialog;
 
-  QString tempfile;
-  tempfile = tmpnam(0L);
+  KTempFile tmpFile;
+  tmpFile.setAutoDelete(true); // delete file when we are done.
+  QString tempfile = tmpFile.name();
 
   save_cddb_entry(tempfile,true);
 
@@ -515,7 +517,6 @@
   file.close();
   //  file2.close();   // *****
 
-  unlink(QFile::encodeName(tempfile));
   kdDebug() << "DONE SENDING\n" << endl;
 } // upload
 
