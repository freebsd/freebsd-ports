--- src/modules/ssl/apache_ssl.c	Wed Dec  5 08:24:16 2001
+++ src/modules/ssl/apache_ssl.c	Mon Mar  4 04:17:11 2002
@@ -1254,7 +1254,6 @@
 static void SendSessionToServer(SSL_SESSION *pSession,
 				conn_rec *pCurrentConnection)
     {
-    uchar buf[MAX_SESSION_DER];
     Cache *p;
     uchar *t;
     int nLength;
@@ -1273,13 +1272,13 @@
     memcpy(t,pSession->session_id,pSession->session_id_length);
     p=LocalCacheAdd(t,pSession->session_id_length,tExpiresAt);
 
-    t=buf;
-    nLength=i2d_SSL_SESSION(pSession,&t);
+    nLength=i2d_SSL_SESSION(pSession,NULL);
     assert(nLength > 0);
     assert(nLength <= MAX_SESSION_DER);
 
     p->aucData=malloc(nLength);
-    memcpy(p->aucData,buf,nLength);
+    t=p->aucData;
+    nLength=i2d_SSL_SESSION(pSession,&t);
     p->nData=nLength;
 
     GlobalCacheAdd(p->aucKey,p->nKey,p->aucData,p->nData,tExpiresAt);
