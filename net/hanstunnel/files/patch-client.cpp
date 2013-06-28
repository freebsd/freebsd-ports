--- client.cpp.orig	2010-02-17 17:30:21.000000000 +0200
+++ client.cpp	2013-04-03 16:05:10.000000000 +0300
@@ -27,6 +27,8 @@
 #include <arpa/inet.h>
 #include <syslog.h>
 
+#include <netinet/in.h>
+
 using namespace std;
 
 const Worker::TunnelHeader::Magic Client::magic("hanc");
