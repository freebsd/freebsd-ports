--- driver/others/blas_server.c.orig	2016-04-12 19:29:19 UTC
+++ driver/others/blas_server.c
@@ -70,7 +70,7 @@ USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 /*********************************************************************/
 
 #include "common.h"
-#if defined(OS_LINUX) || defined(OS_NETBSD) || defined(OS_DARWIN) || defined(OS_ANDROID) || defined(OS_SUNOS)
+#if defined(OS_LINUX) || defined(OS_NETBSD) || defined(OS_DARWIN) || defined(OS_ANDROID) || defined(OS_SUNOS) || defined(OS_FREEBSD)
 #include <dlfcn.h>
 #include <signal.h>
 #include <sys/resource.h>
