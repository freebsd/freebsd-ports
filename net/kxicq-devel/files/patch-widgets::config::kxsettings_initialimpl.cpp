--- kxicq/widgets/config/kxsettings_initialimpl.cpp.orig	Sat Jun 22 21:48:10 2002
+++ kxicq/widgets/config/kxsettings_initialimpl.cpp	Sat Jun 22 21:48:34 2002
@@ -25,7 +25,7 @@
 #include <qcheckbox.h>
 #include <qspinbox.h>
 
-kxSettings_InitialImpl::kxSettings_InitialImpl(QWidget *parent, const char *name,WFlags fl = 0 )
+kxSettings_InitialImpl::kxSettings_InitialImpl(QWidget *parent, const char *name,WFlags fl)
 	: kxSettings_Initial(parent,name, fl)
 {
   QStringList list;
