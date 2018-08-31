Fix build with Qt 5.11
Obtained from: https://sourceforge.net/p/qmmp-dev/code/7988/

--- src/plugins/Ui/skinned/hotkeyeditor.cpp.orig	2018-08-31 05:14:29 UTC
+++ src/plugins/Ui/skinned/hotkeyeditor.cpp
@@ -19,6 +19,7 @@
  ***************************************************************************/
 
 #include <QMessageBox>
+#include <QAction>
 #include "actionmanager.h"
 #include "hotkeyeditor.h"
 #include "shortcutdialog.h"
