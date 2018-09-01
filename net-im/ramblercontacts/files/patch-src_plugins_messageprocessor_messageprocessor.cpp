--- src/plugins/messageprocessor/messageprocessor.cpp.orig	2018-09-01 12:37:59 UTC
+++ src/plugins/messageprocessor/messageprocessor.cpp
@@ -117,7 +117,7 @@ void MessageProcessor::writeText(int AOrder, Message &
 			}
 		}
 
-		QRegExp mail("\\b"MAIL_NODE_PATTERN"@"JID_DOMAIN_PATTERN);
+		QRegExp mail("\\b" MAIL_NODE_PATTERN "@" JID_DOMAIN_PATTERN);
 		mail.setCaseSensitivity(Qt::CaseInsensitive);
 		for (QTextCursor cursor = ADocument->find(mail); !cursor.isNull();  cursor = ADocument->find(mail,cursor))
 		{
