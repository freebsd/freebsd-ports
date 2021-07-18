--- retroshare-gui/src/gui/MainWindow.cpp.orig	2018-03-13 19:25:38 UTC
+++ retroshare-gui/src/gui/MainWindow.cpp
@@ -107,7 +107,9 @@
 #include "gui/common/RsCollection.h"
 #include "settings/rsettingswin.h"
 #include "settings/rsharesettings.h"
+#ifdef ENABLE_WEBUI
 #include "settings/WebuiPage.h"
+#endif
 #include "common/StatusDefs.h"
 #include "gui/notifyqt.h"
 
