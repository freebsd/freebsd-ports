--- backend/flipperzero/protobufsession.cpp.orig	2023-03-27 09:51:38 UTC
+++ backend/flipperzero/protobufsession.cpp
@@ -445,7 +445,7 @@ const QString ProtobufSession::protobufPluginFileName(
     return QStringLiteral("flipperproto%1.dll").arg(versionMajor);
 #elif defined(Q_OS_MAC)
     return QStringLiteral("libflipperproto%1.dylib").arg(versionMajor);
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_UNIX)
     return QStringLiteral("libflipperproto%1.so").arg(versionMajor);
 #else
 #error "Unsupported OS"
