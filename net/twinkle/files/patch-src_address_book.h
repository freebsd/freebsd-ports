--- src/address_book.h	Sun Jan  7 02:47:33 2007
+++ src/address_book.h	Sun Feb  4 17:40:26 2007
@@ -25,6 +25,8 @@
 #include "user.h"
 #include "sockets/url.h"
 #include "threads/mutex.h"
+#include <sys/types.h>
+#include <sys/stat.h>
 
 using namespace std;
 
