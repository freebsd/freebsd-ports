--- tensorflow/contrib/ignite/kernels/client/ignite_plain_client_unix.cc.orig	2019-10-14 21:08:43 UTC
+++ tensorflow/contrib/ignite/kernels/client/ignite_plain_client_unix.cc
@@ -19,6 +19,10 @@ limitations under the License.
 #include <sys/socket.h>
 #include <unistd.h>
 
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
+
 #include <iostream>
 #include <map>
 
