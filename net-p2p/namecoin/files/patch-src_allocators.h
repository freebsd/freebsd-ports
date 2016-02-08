--- src/allocators.h.orig	2014-12-18 14:47:02 UTC
+++ src/allocators.h
@@ -7,7 +7,9 @@
 
 #include <string.h>
 #include <string>
+#ifndef Q_MOC_RUN
 #include <boost/thread/mutex.hpp>
+#endif
 #include <map>
 #include <openssl/crypto.h> // for OPENSSL_cleanse()
 
