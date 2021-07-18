--- retroshare-gui/src/gui/settings/rsettingswin.cpp.orig	2018-03-13 19:25:38 UTC
+++ retroshare-gui/src/gui/settings/rsettingswin.cpp
@@ -41,7 +41,9 @@
 #include "PostedPage.h"
 #include "PluginsPage.h"
 #include "ServicePermissionsPage.h"
+#ifdef ENABLE_WEBUI
 #include "WebuiPage.h"
+#endif
 #include "rsharesettings.h"
 #include "gui/notifyqt.h"
 #include "gui/common/FloatingHelpBrowser.h"
