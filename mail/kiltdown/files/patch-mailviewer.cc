--- kiltdown/mailviewer.cc	2001-05-13 23:25:23.000000000 -0400
+++ kiltdown/mailviewer.cc	2008-05-21 23:27:52.000000000 -0400
@@ -951,11 +951,11 @@
                                   : ID_HIGH_PRIORITY_TEXT);
             if (pstr) {
-                QPixmap p(p == LowPriority ? lowpriIcon : priorityhdrIcon);
-                priorityPixLabel->setPixmap(p);
-                priorityPixLabel->setGeometry(4, top, p.width() + 1, ctlHeight);
+                QPixmap qp(p == LowPriority ? lowpriIcon : priorityhdrIcon);
+                priorityPixLabel->setPixmap(qp);
+                priorityPixLabel->setGeometry(4, top, qp.width() + 1, ctlHeight);
                 priorityLabel->setText(pstr);
                 localFree(pstr);
-                priorityLabel->setGeometry(p.width() + 5, top,
-                                           this->width() - p.width() - 13,
+                priorityLabel->setGeometry(qp.width() + 5, top,
+                                           this->width() - qp.width() - 13,
                                            ctlHeight);
                 top += ctlHeight + 5;
@@ -1563,8 +1563,8 @@
 )
 {
-    LinkList<unsigned int> list;
+    LinkList<void *> list;
     const char *pstr, *pstr2;
     SelectMeDialog *smd;
-    unsigned int ui;
+    void *ui;
     Attachment *a;
     ERRCODE er;
@@ -1592,5 +1592,5 @@
         a->getFileName(&pstr);
         if (pstr) {
-            smd->addItem(pstr, (unsigned int)a);
+            smd->addItem(pstr, (void *)a);
             localFree(pstr);
         }
