--- fhttpd.h.orig	Fri Dec 15 00:34:52 2006
+++ fhttpd.h	Fri Dec 15 00:35:10 2006
@@ -249,8 +249,8 @@
 void response(ServerConnection *client,char *fmt,...);
 void hugeresponse(ServerConnection *client,char *buffer,unsigned long size);
 void setexitafterresponse(ServerConnection *client,int closeonexit);
-int ControlFTPServer::getexitafterresponse(ServerConnection *client);
-void ControlFTPServer::emptyresponse(ServerConnection *client);
+int getexitafterresponse(ServerConnection *client);
+void emptyresponse(ServerConnection *client);
 void suspendpollforresponse(ServerConnection *client,int startpollonexit);
 
 void answer_to_list(char *buffer,int i,int *syncexpected,
