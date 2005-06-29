--- lib/senna_in.h.orig	Fri Jun  3 23:59:02 2005
+++ lib/senna_in.h	Wed Jun 29 01:59:39 2005
@@ -14,6 +14,9 @@
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */
 
+#ifndef _SENNA_IN_H
+#define _SENNA_IN_H
+
 #include "config.h"
 
 #ifdef HAVE_STDLIB_H
@@ -22,8 +25,14 @@
 
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
