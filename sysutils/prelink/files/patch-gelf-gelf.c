diff -Nur gelf/gelf.c gelf/gelf.c
--- gelf/gelf.c	2013-02-19 23:54:34.000000000 +0200
+++ gelf/gelf.c	2013-02-19 23:50:31.000000000 +0200
@@ -17,7 +17,9 @@
    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
 #include <config.h>
-#include <elf.h>
+#include "elf.h"
+#define _SYS_ELF32_H_ 1
+#define _SYS_ELF64_H_ 1
 #include <libelf.h>
 #include <stdlib.h>
 #include <string.h>
