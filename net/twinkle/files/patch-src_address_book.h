--- src/address_book.h	2007-11-11 13:35:53.000000000 -0500
+++ src/address_book.h	2007-11-11 13:36:25.000000000 -0500
@@ -27,6 +27,9 @@
 #include <string>
 #include <list>
 
+#include <sys/types.h>
+#include <sys/stat.h>
+
 #include "user.h"
 #include "sockets/url.h"
 #include "threads/mutex.h"
