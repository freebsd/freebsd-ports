--- src/rip/k3bmovieview.cpp.orig	Fri Feb  6 12:08:51 2004
+++ src/rip/k3bmovieview.cpp	Sun Jan  2 09:30:08 2005
@@ -223,8 +223,11 @@
     }
 
     QWidget::show();
+    if (longestTitle)
+    {
     longestTitle->parent()->setOpen( true );
     m_listView->setSelected( longestTitle, true );
+    }
   } else {
     // error during parsing
     emit notSupportedDisc( m_device->devicename() );
