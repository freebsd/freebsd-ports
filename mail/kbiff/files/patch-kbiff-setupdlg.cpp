--- kbiff/setupdlg.cpp.orig	Tue Oct 15 20:13:12 2002
+++ kbiff/setupdlg.cpp	Tue Oct 15 20:16:13 2002
@@ -779,6 +779,8 @@
   checkBeep = new QCheckBox(i18n("System &Beep"), this);
   checkNotify = new QCheckBox(i18n("N&otify"), this);
   checkStatus = new QCheckBox(i18n("&Floating Status"), this);
+  checkStatus->setChecked(false);
+  checkStatus->setEnabled(false); 	
 
   // connect some slots and signals
   connect(buttonBrowsePlaySound, SIGNAL(clicked()), SLOT(browsePlaySound()));
