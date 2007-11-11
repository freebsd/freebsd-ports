--- src/connection.h.orig	2007-11-08 07:30:05.000000000 +0000
+++ src/connection.h	2007-11-08 07:30:21.000000000 +0000
@@ -25,7 +25,7 @@
 	String *name;
 	Session *sess;
 
-	int Connection::fdConnect(void);
+	int fdConnect(void);
 
 public:
 	virtual int connect(void) = 0;
