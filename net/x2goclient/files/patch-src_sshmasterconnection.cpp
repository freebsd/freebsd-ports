--- src/sshmasterconnection.cpp.orig	2016-03-24 20:39:27 UTC
+++ src/sshmasterconnection.cpp
@@ -28,6 +28,9 @@
 #include <QDir>
 #include <QTemporaryFile>
 #ifndef Q_OS_WIN
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #endif
 #include <math.h>
@@ -277,7 +280,11 @@ void SshMasterConnection::addReverseTunn
         if(!reverseTunnelRequest[i].listen)
         {
             reverseTunnelRequest[i].listen=true;
+#if LIBSSH_VERSION_MAJOR == 0 && LIBSSH_VERSION_MINOR <= 6
             int rc=ssh_forward_listen(my_ssh_session, NULL, reverseTunnelRequest[i].forwardPort, NULL);
+#else
+            int rc=ssh_channel_listen_forward(my_ssh_session, NULL, reverseTunnelRequest[i].forwardPort, NULL);
+#endif
             if(rc==SSH_OK)
             {
                 emit reverseTunnelOk(reverseTunnelRequest[i].creator);
