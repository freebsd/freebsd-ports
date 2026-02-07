--- src/mailboxmenu.cpp.orig
+++ src/mailboxmenu.cpp
@@ -20,6 +20,7 @@
 //
 //
 #include "mailboxmenu.h"
+#include <cstdlib>
 
 MailboxMenu::MailboxMenu(ToolWindow *toolwindow) :
         Menu(*toolwindow, toolwindow->getCurrentScreen()), bbtool(toolwindow)
