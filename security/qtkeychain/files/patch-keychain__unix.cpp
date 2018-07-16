--- keychain_unix.cpp.orig      2018-07-14 17:48:08 UTC
+++ keychain_unix.cpp
@@ -91,7 +91,7 @@ static bool isKwallet5Available()
     // a wallet can be opened.

     iface.setTimeout(500);
-    QDBusMessage reply = iface.call(QStringLiteral("networkWallet"));
+    QDBusMessage reply = iface.call(QLatin1String("networkWallet"));
     return reply.type() == QDBusMessage::ReplyMessage;
 }

