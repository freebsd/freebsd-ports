--- kxicq/widgets/kxreminderdialogimpl.cpp.orig	Sat Jun 22 21:59:52 2002
+++ kxicq/widgets/kxreminderdialogimpl.cpp	Sat Jun 22 22:00:41 2002
@@ -17,7 +17,7 @@
 int nRemindIn = 22;
 
 
-kxReminderDialogImpl::kxReminderDialogImpl(  kxReminderEvent *ev, kxReminderDaemon *reminderDaemon, QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 )
+kxReminderDialogImpl::kxReminderDialogImpl(  kxReminderEvent *ev, kxReminderDaemon *reminderDaemon, QWidget* parent, const char* name, bool modal, WFlags fl)
   : kxReminderDialog( parent, name, modal, fl )
 {
   this->reminderDaemon = reminderDaemon;
@@ -112,4 +112,4 @@
     }
     QString s = QString::number(amount) + QString(" ") + value;
     return s;
-}
+}
