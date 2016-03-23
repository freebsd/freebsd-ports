--- driver/others/blas_server.c.orig	2015-10-27 20:44:50 UTC
+++ driver/others/blas_server.c
@@ -70,7 +70,7 @@ USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 /*********************************************************************/
 
 #include "common.h"
-#if defined(OS_LINUX) || defined(OS_NETBSD) || defined(OS_DARWIN) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_NETBSD) || defined(OS_DARWIN) || defined(OS_ANDROID) || defined(OS_FREEBSD)
 #include <dlfcn.h>
 #include <signal.h>
 #include <sys/resource.h>
