--- retroshare-gui/src/main.cpp.orig	2018-03-13 19:25:38 UTC
+++ retroshare-gui/src/main.cpp
@@ -41,7 +41,9 @@
 #include "gui/FileTransfer/TransfersDialog.h"
 #include "gui/settings/RsharePeerSettings.h"
 #include "gui/settings/rsharesettings.h"
+#ifdef ENABLE_WEBUI
 #include "gui/settings/WebuiPage.h"
+#endif
 #include "idle/idle.h"
 #include "lang/languagesupport.h"
 #include "util/RsGxsUpdateBroadcast.h"
