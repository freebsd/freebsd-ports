--- src/rip/k3bmovieview.cpp.orig	Thu Jun 12 16:07:42 2003
+++ src/rip/k3bmovieview.cpp	Fri Nov  7 12:35:44 2003
@@ -248,8 +248,11 @@
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
