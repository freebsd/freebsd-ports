--- protocols/irc/libkirc/plugins/ctcp/kircctcpmessages.cpp.orig	2018-09-07 10:14:53 UTC
+++ protocols/irc/libkirc/plugins/ctcp/kircctcpmessages.cpp
@@ -101,7 +101,7 @@ void StdCommands::CtcpRequest_dcc(const 
 		{
 			QFileInfo file(fileName);
 			QString noWhiteSpace = file.fileName();
-			if (noWhiteSpace.contains(' ') > 0)
+			if (noWhiteSpace.contains(' ') )
 				noWhiteSpace.replace(QRegExp("\\s+"), "_");
 
 			TransferServer *server = TransferHandler::self()->createServer(this, nickname, type, fileName, file.size());
