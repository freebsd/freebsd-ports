--- lib/senna_in.h.orig	Sat Aug 27 23:59:02 2005
+++ lib/senna_in.h	Sun Aug 28 13:13:56 2005
@@ -14,16 +14,28 @@
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
+#ifndef _SENNA_IN_H
+#define _SENNA_IN_H
+
 #include "config.h"
 
 #ifdef HAVE_STDLIB_H
 #include <stdlib.h>
 #endif /* HAVE_STDLIB_H */
 
+/* #include <sys/types.h> */
+#include <unistd.h>
+
 #ifdef HAVE_STDINT_H
 #include <stdint.h>
+#else
+#include <inttypes.h>
+typedef	uint8_t	uint_least8_t;
+typedef	int8_t	int_least8_t;
 #endif /* HAVE_STDINT_H */
 
 #ifndef _SENNA_H
 #include "senna.h"
 #endif /* _SENNA_H */
+
+#endif /* _SENNA_IN_H */
