--- kxicq/widgets/config/kxsettings_ignoreimpl.cpp.orig	Sat Jun 22 21:49:49 2002
+++ kxicq/widgets/config/kxsettings_ignoreimpl.cpp	Sat Jun 22 21:50:10 2002
@@ -29,7 +29,7 @@
 #include <qlistview.h>
 #include <qpushbutton.h>
 
-kxSettings_IgnoreImpl::kxSettings_IgnoreImpl(QWidget *parent, const char *name,WFlags fl = 0 )
+kxSettings_IgnoreImpl::kxSettings_IgnoreImpl(QWidget *parent, const char *name,WFlags fl)
 	: kxSettings_Ignore(parent,name, fl)
 {
 	addButton->setEnabled(FALSE);	
