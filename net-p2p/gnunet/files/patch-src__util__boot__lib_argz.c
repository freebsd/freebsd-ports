--- src/util/boot/lib_argz.c.orig	2009-11-17 03:51:38.000000000 +0900
+++ src/util/boot/lib_argz.c	2010-01-05 00:27:35.000000000 +0900
@@ -16,6 +16,7 @@
    with this program; if not, write to the Free Software Foundation,
    Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA. */
 
+#include "platform.h"
 #include <errno.h>
 #include <stdlib.h>
 #include <string.h>
