--- ./config/appearance-config-tab.cpp.orig	2013-04-01 11:36:44.000000000 -0700
+++ ./config/appearance-config-tab.cpp	2013-04-02 17:02:32.193641735 -0700
@@ -174,7 +174,8 @@
     message.setTime(QDateTime::currentDateTime());
     ui->chatView->addContentMessage(message);
 
-    message = AdiumThemeContentInfo(AdiumThemeMessageInfo::HistoryRemoteToLocal);
+    AdiumThemeContentInfo message2(AdiumThemeMessageInfo::HistoryRemoteToLocal);
+    message = message2;
     message.setMessage(i18nc("Example message in preview conversation","Bye Bye"));
     message.setSenderDisplayName(i18nc("Example email", "larry@example.com"));
     message.setSenderScreenName(i18nc("Example name", "Larry Demo"));
@@ -182,7 +183,8 @@
     message.setTime(QDateTime::currentDateTime());
     ui->chatView->addContentMessage(message);
 
-    message = AdiumThemeContentInfo(AdiumThemeMessageInfo::HistoryLocalToRemote);
+    AdiumThemeContentInfo message3(AdiumThemeMessageInfo::HistoryLocalToRemote);
+    message = message3;
     message.setMessage(i18nc("Example message in preview conversation","Have fun!"));
     message.setSenderDisplayName(i18nc("Example email", "ted@example.com"));
     message.setSenderScreenName(i18nc("Example name", "Ted Example"));
@@ -190,7 +192,8 @@
     message.setTime(QDateTime::currentDateTime());
     ui->chatView->addContentMessage(message);
 
-    message = AdiumThemeContentInfo(AdiumThemeMessageInfo::HistoryLocalToRemote);
+    AdiumThemeContentInfo message4(AdiumThemeMessageInfo::HistoryLocalToRemote);
+    message = message4;
     message.setMessage(i18nc("Example message in preview conversation","cya"));
     message.setSenderDisplayName(i18nc("Example email", "ted@example.com"));
     message.setSenderScreenName(i18nc("Example name", "Ted Example"));
@@ -204,14 +207,16 @@
     statusMessage.setService(i18n("Jabber"));
     ui->chatView->addStatusMessage(statusMessage);
 
-    statusMessage = AdiumThemeStatusInfo(true);
+    AdiumThemeStatusInfo statusMessage2(true);
+    statusMessage = statusMessage2;
     statusMessage.setMessage(i18nc("Example message in preview conversation","Ted Example has left the chat.")); //FIXME sync this with chat text logic.
     statusMessage.setTime(QDateTime::currentDateTime());
     statusMessage.setService(i18n("Jabber"));
     statusMessage.setStatus(QLatin1String("away"));
     ui->chatView->addStatusMessage(statusMessage);
 
-    message = AdiumThemeContentInfo(AdiumThemeMessageInfo::RemoteToLocal);
+    AdiumThemeContentInfo message5(AdiumThemeMessageInfo::RemoteToLocal);
+    message = message5;
     message.setMessage(i18nc("Example message in preview conversation","Hello Ted"));
     message.setSenderDisplayName(i18nc("Example email", "larry@example.com"));
     message.setSenderScreenName(i18nc("Example name", "Larry Demo"));
@@ -220,7 +225,8 @@
     message.setTime(QDateTime::currentDateTime());
     ui->chatView->addContentMessage(message);
 
-    message = AdiumThemeContentInfo(AdiumThemeMessageInfo::RemoteToLocal);
+    AdiumThemeContentInfo message6(AdiumThemeMessageInfo::RemoteToLocal);
+    message = message6;
     message.setMessage(i18nc("Example message in preview conversation","What's up?"));
     message.setSenderDisplayName(i18nc("Example email", "larry@example.com"));
     message.setSenderScreenName(i18nc("Example name", "Larry Demo"));
@@ -228,7 +234,8 @@
     message.setTime(QDateTime::currentDateTime());
     ui->chatView->addContentMessage(message);
 
-    message = AdiumThemeContentInfo(AdiumThemeMessageInfo::LocalToRemote);
+    AdiumThemeContentInfo message7(AdiumThemeMessageInfo::LocalToRemote);
+    message = message7;
     message.setMessage(i18nc("Example message in preview conversation","Check out which cool adium themes work "
                             "<a href=\"http://community.kde.org/KTp/Components/Chat_Window/Themes\">"
                             "here</a>!"));
@@ -239,7 +246,8 @@
     ui->chatView->addContentMessage(message);
 
     if ( m_groupChat == true) {
-        message = AdiumThemeContentInfo(AdiumThemeMessageInfo::RemoteToLocal);
+        AdiumThemeContentInfo message8(AdiumThemeMessageInfo::RemoteToLocal);
+        message = message8;
         message.setMessage(i18nc("Example message in preview conversation","Hello"));
         message.setSenderDisplayName(i18nc("Example email", "bob@example.com"));
         message.setSenderScreenName(i18nc("Example name", "Bob Example"));
@@ -248,7 +256,8 @@
         ui->chatView->addContentMessage(message);
     }
 
-    message = AdiumThemeContentInfo(AdiumThemeMessageInfo::LocalToRemote);
+    AdiumThemeContentInfo message9(AdiumThemeMessageInfo::LocalToRemote);
+    message = message9;
     message.setMessage(i18nc("Example message in preview conversation","A different example message"));
     message.setSenderDisplayName(i18nc("Example email", "ted@example.com"));
     message.setSenderScreenName(i18nc("Example name", "Ted Example"));
@@ -257,14 +266,16 @@
     ui->chatView->addContentMessage(message);
 
     if (ui->chatView->showPresenceChanges()) {
-        statusMessage = AdiumThemeStatusInfo();
+        AdiumThemeStatusInfo statusMessage3;
+	statusMessage = statusMessage3;
         statusMessage.setMessage(i18nc("Example message in preview conversation","Ted Example is now Away.")); //FIXME sync this with chat text logic.
         statusMessage.setTime(QDateTime::currentDateTime());
         statusMessage.setService(i18n("Jabber"));
         statusMessage.setStatus(QLatin1String("away"));
         ui->chatView->addStatusMessage(statusMessage);
 
-        statusMessage = AdiumThemeStatusInfo();
+        AdiumThemeStatusInfo statusMessage4;
+	statusMessage = statusMessage4;
         statusMessage.setMessage(i18nc("Example message in preview conversations","Ted Example has left the chat.")); //FIXME sync this with chat text logic.
         statusMessage.setTime(QDateTime::currentDateTime());
         statusMessage.setService(i18n("Jabber"));
