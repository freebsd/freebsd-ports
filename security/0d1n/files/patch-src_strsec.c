--- src/strsec.c.orig	2023-02-20 12:39:57 UTC
+++ src/strsec.c
@@ -16,11 +16,11 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#include "strsec.h"
 
 #if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && \
     !defined(__bsdi__) && !defined(__APPLE__)
 
-#include "strsec.h"
 /*
  * Copy src to string dst of size siz.  At most siz-1 characters
  * will be copied.  Always NUL terminates (unless siz == 0).
