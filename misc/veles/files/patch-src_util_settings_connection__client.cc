--- src/util/settings/connection_client.cc.orig	2019-06-14 02:37:34 UTC
+++ src/util/settings/connection_client.cc
@@ -202,6 +202,8 @@ QString serverScriptDefault() {
   server_script = qApp->applicationDirPath() + "/../veles-server/srv.py";
 #elif defined(Q_OS_LINUX)
   server_script = qApp->applicationDirPath() + "/../share/veles-server/srv.py";
+#elif defined(Q_OS_FREEBSD)
+  server_script = qApp->applicationDirPath() + "/veles-server";
 #elif defined(Q_OS_MAC)
   server_script =
       qApp->applicationDirPath() + "/../Resources/veles-server/srv.py";
