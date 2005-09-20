--- src/uuid.cpp	Mon Jul 18 21:54:08 2005
+++ src/uuid.cpp	Sun Sep 18 21:21:21 2005
@@ -12,7 +12,8 @@
 
 #include "uuid.h"
 #include <qstring.h>
-#include <openssl/rand.h>
+#include <unistd.h>
+#include <fcntl.h>
 
 UUID::UUID(): QByteArray(UUID_LEN)/*{{{*/
 {
@@ -35,7 +36,9 @@
 
 void UUID::generate()/*{{{*/
 {
-	RAND_bytes((unsigned char *)data(), UUID_LEN);
+	int rfd = open("/dev/random", O_RDONLY);
+	read(rfd, (void *)data(), UUID_LEN);
+	close(rfd);
 }/*}}}*/
 
 void UUID::set(const unsigned char *data)/*{{{*/
