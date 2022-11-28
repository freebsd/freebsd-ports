--- backend/flipperzero/protobufsession.cpp.orig	2022-11-27 21:43:32 UTC
+++ backend/flipperzero/protobufsession.cpp
@@ -426,7 +426,7 @@ const QString ProtobufSession::protobufPluginFileName(
     return QStringLiteral("flipperproto%1.dll").arg(versionMajor);
 #elif defined(Q_OS_MAC)
     return QStringLiteral("libflipperproto%1.dylib").arg(versionMajor);
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_UNIX)
     return QStringLiteral("libflipperproto%1.so").arg(versionMajor);
 #else
 #error "Unsupported OS"
