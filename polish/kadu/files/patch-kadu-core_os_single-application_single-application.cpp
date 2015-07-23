--- kadu-core/os/single-application/single-application.cpp.orig	2015-02-21 00:27:48 UTC
+++ kadu-core/os/single-application/single-application.cpp
@@ -30,6 +30,7 @@
 #include <QtCore/QRegExp>
 #include <QtNetwork/QLocalServer>
 #include <QtNetwork/QLocalSocket>
+#include <QString>
 #include <memory>
 
 #if defined(Q_OS_WIN)
@@ -107,7 +108,7 @@ QString SingleApplication::socketName(co
 {
 	auto idc = applicationId.toUtf8();
 	auto idNum = qChecksum(idc.constData(), static_cast<uint>(idc.size()));
-	auto result = QString{QLatin1String{"qtsingleapp-"} + prefix + QLatin1Char{'-'} + QString::number(idNum, 16)};
+	auto result = QString(QLatin1String{"qtsingleapp-"} + prefix + QLatin1Char{'-'} + QString::number(idNum, 16));
 
 #if defined(Q_OS_WIN)
 	if (!pProcessIdToSessionId)
@@ -131,7 +132,7 @@ QString SingleApplication::socketName(co
 
 QString SingleApplication::lockName(const QString &socketName)
 {
-	return QString{QDir{QDir::tempPath()}.absolutePath() + QLatin1Char{'/'} + socketName + QLatin1String{"-lockfile"}};
+	return QString(QDir{QDir::tempPath()}.absolutePath() + QLatin1Char{'/'} + socketName + QLatin1String{"-lockfile"});
 }
 
 void SingleApplication::startServer()
