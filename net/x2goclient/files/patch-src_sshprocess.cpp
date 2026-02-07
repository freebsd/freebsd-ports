--- src/sshprocess.cpp.orig	2018-06-25 20:21:49 UTC
+++ src/sshprocess.cpp
@@ -24,6 +24,9 @@
 
 #include <QProcess>
 #ifndef Q_OS_WIN
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netinet/tcp.h>
 #endif
@@ -140,7 +143,7 @@ void SshProcess::tunnelLoop()
     address.sin_family=AF_INET;
     address.sin_addr.s_addr=htonl(INADDR_LOOPBACK);
     address.sin_port=htons(localPort);
-    if (bind(serverSocket,(struct sockaddr*) &address,sizeof(address))!=0)
+    if (::bind(serverSocket,(struct sockaddr*) &address,sizeof(address))!=0)
     {
         QString err=tr("Error binding ")+localHost+":"+QString::number(localPort);
         x2goDebug<<err<<endl;
@@ -209,7 +212,7 @@ void SshProcess::startNormal(const QString& cmd, bool 
     }
     if(!masterCon->useKerberos())
     {
-        QString shcmd = "bash -l -c 'echo \"X2GODATABEGIN:" + uuidStr + "\"; " + pathString + "export TERM=\"dumb\"; "+cmd+"; echo \"X2GODATAEND:" + uuidStr + "\";'";
+        QString shcmd = "sh -c 'echo \"X2GODATABEGIN:" + uuidStr + "\"; " + pathString + "export TERM=\"dumb\"; "+cmd+"; echo \"X2GODATAEND:" + uuidStr + "\";'";
         x2goDebug << "this="<<this<<" Running masterCon->addChannelConnection(this, '" << uuidStr << "', '" << shcmd.left (200) << "');";
         masterCon->addChannelConnection(this, uuidStr, shcmd);
         connect(masterCon,SIGNAL(stdOut(SshProcess*,QByteArray)),this,SLOT(slotStdOut(SshProcess*,QByteArray)));
@@ -231,7 +234,7 @@ void SshProcess::startNormal(const QString& cmd, bool 
          * as there is no preceding "outer double quote" the whole argument
          * is wrapped in.
          */
-        shcmd = "bash -l -c 'echo \"X2GODATABEGIN:" + uuidStr + "\";" + pathString + "export TERM=\"dumb\"; "+cmd+"; echo \"X2GODATAEND:" + uuidStr + "\";'";
+        shcmd = "sh -c 'echo \"X2GODATABEGIN:" + uuidStr + "\";" + pathString + "export TERM=\"dumb\"; "+cmd+"; echo \"X2GODATAEND:" + uuidStr + "\";'";
 
         proc=new QProcess(this);
         QString local_cmd = "";
