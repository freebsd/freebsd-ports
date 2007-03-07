--- src/freshklam.cpp.orig	Tue Mar  6 11:05:52 2007
+++ src/freshklam.cpp	Tue Mar  6 11:06:44 2007
@@ -122,6 +122,8 @@
     software_layout->setColStretch(0, 1);
     software_layout->setColStretch(1, 1);
 
+    software_group->hide();
+
 
     //Dazuko
     QWidget *dazuko_hlp = new QWidget( software_group );
