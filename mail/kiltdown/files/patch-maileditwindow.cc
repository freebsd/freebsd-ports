--- kiltdown/maileditwindow.cc.orig	Mon May 14 05:25:23 2001
+++ kiltdown/maileditwindow.cc	Mon Sep  9 12:02:02 2002
@@ -451,7 +451,7 @@
     er = (*pwindow)->initialize();
     RETURN_ON_FAILURE(er);
 
-    (*pwindow)->editBox->setUndoEnabled(false);
+    //(*pwindow)->editBox->setUndoEnabled(false);
 
     /**
      * Lastly, insert the user's signature.
@@ -461,7 +461,7 @@
 
     (*pwindow)->editBox->insert("\n");
     (*pwindow)->editBox->setCursorPosition(0, 0);
-    (*pwindow)->editBox->setUndoEnabled(true);
+    //(*pwindow)->editBox->setUndoEnabled(true);
 
     return S_OK;
 }
@@ -1008,7 +1008,7 @@
     localFree(subject);
 
     (*pwindow)->subjectEdit->setText(buf);
-    (*pwindow)->editBox->setUndoEnabled(false);
+    //(*pwindow)->editBox->setUndoEnabled(false);
 
     /**
      * now go and extract the to/from information and write out the header.
@@ -1041,7 +1041,7 @@
     (*pwindow)->editBox->insert("\n\n\n");
     (*pwindow)->editBox->setCursorPosition(0, 0);
     (*pwindow)->toEdit->setFocus();
-    (*pwindow)->editBox->setUndoEnabled(true);
+    //(*pwindow)->editBox->setUndoEnabled(true);
 
 
     return S_OK;
@@ -2121,7 +2121,7 @@
     er = (*pwindow)->initialize();
     GOTO_ON_FAILURE(er, Error);
 
-    (*pwindow)->editBox->setUndoEnabled(false);
+    //(*pwindow)->editBox->setUndoEnabled(false);
     (*pwindow)->toEdit->clear();
     (*pwindow)->ccEdit->clear();
 
@@ -2211,11 +2211,11 @@
     (*pwindow)->editBox->setCursorPosition(0, 0);
     (*pwindow)->toEdit->setFocus();
 
-    (*pwindow)->editBox->setUndoEnabled(true);
+    //(*pwindow)->editBox->setUndoEnabled(true);
     return S_OK;
 
   Error:
-      (*pwindow)->editBox->setUndoEnabled(true);
+      //(*pwindow)->editBox->setUndoEnabled(true);
     delete *pwindow;
     return er;
 
@@ -2593,7 +2593,7 @@
     const char *pstr;
     ERRCODE er;
 
-    editbox->setUndoEnabled(false);
+    //editbox->setUndoEnabled(false);
     editbox->end();
 
     if (addsep && list.countElements() && !editbox->text().isEmpty())
@@ -2611,7 +2611,7 @@
         er = list.nextElement(&pstr);
     }
 
-    editbox->setUndoEnabled(true);
+    //editbox->setUndoEnabled(true);
 }
 
 
