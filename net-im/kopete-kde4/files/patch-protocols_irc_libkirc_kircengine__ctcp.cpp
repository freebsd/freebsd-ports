--- protocols/irc/libkirc/kircengine_ctcp.cpp.orig	2018-09-07 10:14:46 UTC
+++ protocols/irc/libkirc/kircengine_ctcp.cpp
@@ -153,7 +153,7 @@ void Engine::CtcpRequest_dcc(const QStri
 		{
 			QFileInfo file(fileName);
 			QString noWhiteSpace = file.fileName();
-			if (noWhiteSpace.contains(' ') > 0)
+			if (noWhiteSpace.contains(' ') )
 				noWhiteSpace.replace(QRegExp("\\s+"), "_");
 
 			TransferServer *server = TransferHandler::self()->createServer(this, nickname, type, fileName, file.size());
