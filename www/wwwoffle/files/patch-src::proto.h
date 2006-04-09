--- src/proto.h~	Thu Dec 15 04:27:22 2005
+++ src/proto.h	Fri Apr  7 14:55:06 2006
@@ -62,7 +62,7 @@
 char /*@null@*/ /*@only@*/ *HTTP_Open(URL *Url);
 char /*@null@*/ /*@only@*/ *HTTP_Request(URL *Url,Header *request_head,Body *request_body);
 int   HTTP_ReadHead(/*@out@*/ Header **reply_head);
-int   HTTP_ReadBody(char *s,size_t n);
+ssize_t   HTTP_ReadBody(char *s,size_t n);
 int   HTTP_Close(void);
 
 #if USE_GNUTLS
@@ -82,7 +82,7 @@
 char /*@null@*/ /*@only@*/ *FTP_Open(URL *Url);
 char /*@null@*/ /*@only@*/ *FTP_Request(URL *Url,Header *request_head,Body *request_body);
 int   FTP_ReadHead(/*@out@*/ Header **reply_head);
-int   FTP_ReadBody(char *s,size_t n);
+ssize_t   FTP_ReadBody(char *s,size_t n);
 int   FTP_Close(void);
 
 /* In finger.c */
@@ -90,7 +90,7 @@
 char /*@null@*/ /*@only@*/ *Finger_Open(URL *Url);
 char /*@null@*/ /*@only@*/ *Finger_Request(URL *Url,Header *request_head,Body *request_body);
 int   Finger_ReadHead(/*@out@*/ Header **reply_head);
-int   Finger_ReadBody(char *s,size_t n);
+ssize_t   Finger_ReadBody(char *s,size_t n);
 int   Finger_Close(void);
 
 /* In ssl.c */
