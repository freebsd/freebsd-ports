--- kxicq/widgets/config/kxsettings_statusimpl.cpp.orig	Sat Jun 22 21:44:58 2002
+++ kxicq/widgets/config/kxsettings_statusimpl.cpp	Sat Jun 22 21:47:27 2002
@@ -25,7 +25,7 @@
 #include <qcheckbox.h>
 #include <qspinbox.h>
 
-kxSettings_StatusImpl::kxSettings_StatusImpl(QWidget *parent, const char *name,WFlags fl = 0 )
+kxSettings_StatusImpl::kxSettings_StatusImpl(QWidget *parent, const char *name,WFlags fl)
 	: kxSettings_Status(parent,name, fl)
 {
 	QObject::connect(statusCombo, SIGNAL(activated(int)), SLOT(activated(int)));
