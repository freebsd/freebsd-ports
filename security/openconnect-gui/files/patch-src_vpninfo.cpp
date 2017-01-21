--- src/vpninfo.cpp.orig	2016-09-21 11:15:03 UTC
+++ src/vpninfo.cpp
@@ -427,6 +427,8 @@ int VpnInfo::connect()
     const QString osName{"mac-intel"};
 #elif defined Q_OS_LINUX
     const QString osName = QString("linux%1").arg(QSysInfo::buildCpuArchitecture() == "i386" ? "" : "-64").toStdString().c_str();
+#elif defined Q_OS_FREEBSD
+    const QString osName = QString("freebsd%1").arg(QSysInfo::buildCpuArchitecture() == "i386" ? "" : "-64").toStdString().c_str();
 #else
 #error Define OS string of other platforms...
 #endif
