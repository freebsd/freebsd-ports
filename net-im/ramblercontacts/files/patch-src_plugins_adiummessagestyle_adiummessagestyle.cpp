--- src/plugins/adiummessagestyle/adiummessagestyle.cpp.orig	2018-09-01 12:39:15 UTC
+++ src/plugins/adiummessagestyle/adiummessagestyle.cpp
@@ -15,9 +15,9 @@
 #include <QApplication>
 #include <QTextDocument>
 
-#define SHARED_STYLE_PATH                   RESOURCES_DIR"/"RSR_STORAGE_ADIUMMESSAGESTYLES"/"STORAGE_SHARED_DIR
+#define SHARED_STYLE_PATH                   RESOURCES_DIR "/" RSR_STORAGE_ADIUMMESSAGESTYLES "/" STORAGE_SHARED_DIR
 #define STYLE_CONTENTS_PATH                 "Contents"
-#define STYLE_RESOURCES_PATH                STYLE_CONTENTS_PATH"/Resources"
+#define STYLE_RESOURCES_PATH                STYLE_CONTENTS_PATH "/Resources"
 
 #define APPEND_MESSAGE_WITH_SCROLL          "checkIfScrollToBottomIsNeeded(); appendCustumMessage(\"%1\",\"appendMessage\",%2,%3); scrollToBottomIfNeeded();"
 #define APPEND_NEXT_MESSAGE_WITH_SCROLL     "checkIfScrollToBottomIsNeeded(); appendCustumMessage(\"%1\",\"appendNextMessage\",%2,%3); scrollToBottomIfNeeded();"
@@ -56,7 +56,7 @@ AdiumMessageStyle::AdiumMessageStyle(const QString &AS
 	FDelayedAllwaysOn = true;
 	FInfo = styleInfo(AStylePath);
 	FVariants = styleVariants(AStylePath);
-	FResourcePath = AStylePath+"/"STYLE_RESOURCES_PATH;
+	FResourcePath = AStylePath+"/" STYLE_RESOURCES_PATH;
 
 	initStyleSettings();
 	loadTemplates();
@@ -230,7 +230,7 @@ QList<QString> AdiumMessageStyle::styleVariants(const 
 	QList<QString> files;
 	if (!AStylePath.isEmpty())
 	{
-		QDir dir(AStylePath+"/"STYLE_RESOURCES_PATH"/Variants");
+		QDir dir(AStylePath+"/" STYLE_RESOURCES_PATH "/Variants");
 		files = dir.entryList(QStringList("*.css"),QDir::Files,QDir::Name);
 		for (int i=0; i<files.count();i++)
 			files[i].chop(4);
@@ -242,7 +242,7 @@ QMap<QString, QVariant> AdiumMessageStyle::styleInfo(c
 {
 	QMap<QString, QVariant> info;
 
-	QFile file(AStylePath+"/"STYLE_CONTENTS_PATH"/Info.plist");
+	QFile file(AStylePath+"/" STYLE_CONTENTS_PATH "/Info.plist");
 	if (!AStylePath.isEmpty() && file.open(QFile::ReadOnly))
 	{
 		QDomDocument doc;
@@ -365,13 +365,13 @@ QString AdiumMessageStyle::makeStyleTemplate(const IMe
 	if (!QFile::exists(htmlFileName))
 	{
 		FUsingCustomTemplate = false;
-		htmlFileName = qApp->applicationDirPath()+"/"SHARED_STYLE_PATH"/Template.html";
+		htmlFileName = qApp->applicationDirPath()+"/" SHARED_STYLE_PATH "/Template.html";
 	}
 
 	QString html = loadFileData(htmlFileName,QString::null);
 	if (!html.isEmpty())
 	{
-		static QString extendScripts = loadFileData(qApp->applicationDirPath()+"/"SHARED_STYLE_PATH"/Extension.js",QString::null);
+		static QString extendScripts = loadFileData(qApp->applicationDirPath()+"/" SHARED_STYLE_PATH "/Extension.js",QString::null);
 		html.insert(html.indexOf("<script ",0,Qt::CaseInsensitive),QString("<script type='text/javascript'>%1</script>\n").arg(extendScripts));
 
 		QString headerHTML;
@@ -699,24 +699,24 @@ void AdiumMessageStyle::loadTemplates()
 	FOut_ContextHTML =     loadFileData(FResourcePath+"/Outgoing/Context.html",FOut_ContentHTML);
 	FOut_NextContextHTML = loadFileData(FResourcePath+"/Outgoing/NextContext.html",FOut_NextContentHTML);
 
-	FIn_UnreadHTML =       loadFileData(qApp->applicationDirPath()+"/"SHARED_STYLE_PATH"/Incoming/Unread.html", QString::null);
+	FIn_UnreadHTML =       loadFileData(qApp->applicationDirPath()+"/" SHARED_STYLE_PATH "/Incoming/Unread.html", QString::null);
 	FIn_UnreadHTML =       loadFileData(FResourcePath+"/Incoming/Unread.html",FIn_UnreadHTML);
-	FIn_NextUnreadHTML =   loadFileData(qApp->applicationDirPath()+"/"SHARED_STYLE_PATH"/Incoming/NextUnread.html", FIn_UnreadHTML);
+	FIn_NextUnreadHTML =   loadFileData(qApp->applicationDirPath()+"/" SHARED_STYLE_PATH "/Incoming/NextUnread.html", FIn_UnreadHTML);
 	FIn_NextUnreadHTML =   loadFileData(FResourcePath+"/Incoming/NextUnread.html",FIn_NextUnreadHTML);
 
-	FIn_OfflineHTML =      loadFileData(qApp->applicationDirPath()+"/"SHARED_STYLE_PATH"/Incoming/Offline.html", QString::null);
+	FIn_OfflineHTML =      loadFileData(qApp->applicationDirPath()+"/" SHARED_STYLE_PATH "/Incoming/Offline.html", QString::null);
 	FIn_OfflineHTML =      loadFileData(FResourcePath+"/Incoming/Offline.html",FIn_OfflineHTML);
-	FIn_NextOfflineHTML =  loadFileData(qApp->applicationDirPath()+"/"SHARED_STYLE_PATH"/Incoming/NextOffline.html", FIn_OfflineHTML);
+	FIn_NextOfflineHTML =  loadFileData(qApp->applicationDirPath()+"/" SHARED_STYLE_PATH "/Incoming/NextOffline.html", FIn_OfflineHTML);
 	FIn_NextOfflineHTML =  loadFileData(FResourcePath+"/Incoming/NextOffline.html",FIn_NextOfflineHTML);
 
-	FOut_UnreadHTML =      loadFileData(qApp->applicationDirPath()+"/"SHARED_STYLE_PATH"/Outgoing/Unread.html", FIn_UnreadHTML);
+	FOut_UnreadHTML =      loadFileData(qApp->applicationDirPath()+"/" SHARED_STYLE_PATH "/Outgoing/Unread.html", FIn_UnreadHTML);
 	FOut_UnreadHTML =      loadFileData(FResourcePath+"/Outgoing/Unread.html",FOut_UnreadHTML);
-	FOut_NextUnreadHTML =  loadFileData(qApp->applicationDirPath()+"/"SHARED_STYLE_PATH"/Outgoing/NextUnread.html", FOut_UnreadHTML);
+	FOut_NextUnreadHTML =  loadFileData(qApp->applicationDirPath()+"/" SHARED_STYLE_PATH "/Outgoing/NextUnread.html", FOut_UnreadHTML);
 	FOut_NextUnreadHTML =  loadFileData(FResourcePath+"/Outgoing/NextUnread.html",FOut_NextUnreadHTML);
 
-	FOut_OfflineHTML =     loadFileData(qApp->applicationDirPath()+"/"SHARED_STYLE_PATH"/Outgoing/Offline.html", FIn_OfflineHTML);
+	FOut_OfflineHTML =     loadFileData(qApp->applicationDirPath()+"/" SHARED_STYLE_PATH "/Outgoing/Offline.html", FIn_OfflineHTML);
 	FOut_OfflineHTML =     loadFileData(FResourcePath+"/Outgoing/Offline.html",FOut_OfflineHTML);
-	FOut_NextOfflineHTML = loadFileData(qApp->applicationDirPath()+"/"SHARED_STYLE_PATH"/Outgoing/NextOffline.html", FOut_OfflineHTML);
+	FOut_NextOfflineHTML = loadFileData(qApp->applicationDirPath()+"/" SHARED_STYLE_PATH "/Outgoing/NextOffline.html", FOut_OfflineHTML);
 	FOut_NextOfflineHTML = loadFileData(FResourcePath+"/Outgoing/NextOffline.html",FOut_NextOfflineHTML);
 }
 
