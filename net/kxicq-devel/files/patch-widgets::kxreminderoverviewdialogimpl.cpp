--- kxicq/widgets/kxreminderoverviewdialogimpl.cpp.orig	Sat Jun 22 21:55:15 2002
+++ kxicq/widgets/kxreminderoverviewdialogimpl.cpp	Sat Jun 22 21:56:10 2002
@@ -12,7 +12,7 @@
 #define COL_ID   4
 #define COL_TYPE 3
 
-kxReminderOverviewDialogImpl::kxReminderOverviewDialogImpl( kxReminderDaemon *reminderDaemon, QWidget* parent = 0L, const char* name = 0, bool modal = FALSE, WFlags fl = 0 )
+kxReminderOverviewDialogImpl::kxReminderOverviewDialogImpl( kxReminderDaemon *reminderDaemon, QWidget* parent, const char* name, bool modal, WFlags fl)
   : kxReminderOverviewDialog( parent, name, modal, fl )
 {
   this->reminderDaemon = reminderDaemon;
