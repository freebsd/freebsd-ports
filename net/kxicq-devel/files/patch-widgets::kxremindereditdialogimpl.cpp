--- kxicq/widgets/kxremindereditdialogimpl.cpp.orig	Sat Jun 22 21:56:47 2002
+++ kxicq/widgets/kxremindereditdialogimpl.cpp	Sat Jun 22 21:59:10 2002
@@ -13,7 +13,7 @@
 #include <kglobal.h>
 #include <kxcontact.h>
 
-kxReminderEditDialogImpl::kxReminderEditDialogImpl(  kxReminderEventType type, int id, kxReminderDaemon *reminderDaemon, QWidget* parent = 0L, const char* name = 0, bool modal = FALSE, WFlags fl = 0 )
+kxReminderEditDialogImpl::kxReminderEditDialogImpl(  kxReminderEventType type, int id, kxReminderDaemon *reminderDaemon, QWidget* parent, const char* name, bool modal, WFlags fl)
   : kxReminderEditDialog( parent, name, modal, fl )
 {
   this->reminderDaemon = reminderDaemon;
