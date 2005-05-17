--- kiltdown/mailviewer.cc.orig	Sun May 15 22:29:50 2005
+++ kiltdown/mailviewer.cc	Sun May 15 22:28:00 2005
@@ -950,13 +950,13 @@ void MailViewer::layoutComponents()
                                   ? ID_LOW_PRIORITY_TEXT 
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
                 priorityPixLabel->show();
