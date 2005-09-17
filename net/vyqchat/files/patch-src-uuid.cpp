--- src/uuid.cpp.orig	Mon Jul 18 20:54:08 2005
+++ src/uuid.cpp	Sat Sep 17 23:03:48 2005
@@ -12,7 +12,7 @@
 
 #include "uuid.h"
 #include <qstring.h>
-#include <openssl/rand.h>
+#include <fcntl.h>
 
 UUID::UUID(): QByteArray(UUID_LEN)/*{{{*/
 {
@@ -35,7 +35,9 @@
 
 void UUID::generate()/*{{{*/
 {
-	RAND_bytes((unsigned char *)data(), UUID_LEN);
+	int rfd = open("/dev/random", O_RDONLY);
+	read(rfd, (void *)data(), UUID_LEN);
+	close(rfd);
 }/*}}}*/
 
 void UUID::set(const unsigned char *data)/*{{{*/
