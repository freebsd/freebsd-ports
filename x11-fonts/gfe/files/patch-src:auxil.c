Only in src.dist: about_dialog.o
diff -u src.dist/auxil.c src/auxil.c
--- src.dist/auxil.c	Thu Dec 27 06:00:20 2001
+++ src/auxil.c	Thu Dec 27 06:01:59 2001
@@ -16,7 +16,7 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 #include <ctype.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <gtk/gtk.h>
 
 #include "auxil.h"
Only in src.dist: auxil.o
diff -u src.dist/bdf.c src/bdf.c
--- src.dist/bdf.c	Thu Dec 27 06:00:20 2001
+++ src/bdf.c	Thu Dec 27 06:01:59 2001
@@ -18,7 +18,7 @@
 #include <gtk/gtk.h>
 
 #include <ctype.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "auxil.h"
 #include "bdf.h"
diff -u src.dist/bitmap.c src/bitmap.c
--- src.dist/bitmap.c	Thu Dec 27 06:00:20 2001
+++ src/bitmap.c	Thu Dec 27 06:01:59 2001
@@ -16,7 +16,7 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 #include <gtk/gtk.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "bitmap.h"
 
diff -u src.dist/file.c src/file.c
--- src.dist/file.c	Thu Dec 27 06:00:20 2001
+++ src/file.c	Thu Dec 27 06:01:59 2001
@@ -16,7 +16,7 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 #include <gtk/gtk.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "auxil.h"
 #include "bdf.h"
diff -u src.dist/font.c src/font.c
--- src.dist/font.c	Thu Dec 27 06:00:20 2001
+++ src/font.c	Thu Dec 27 06:01:59 2001
@@ -16,7 +16,7 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 #include <gtk/gtk.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "auxil.h"
 #include "font.h"
diff -u src.dist/glyph.c src/glyph.c
--- src.dist/glyph.c	Thu Dec 27 06:00:20 2001
+++ src/glyph.c	Thu Dec 27 06:01:59 2001
@@ -16,7 +16,7 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 #include <gtk/gtk.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "auxil.h"
 #include "glyph.h"
diff -u src.dist/gui.c src/gui.c
--- src.dist/gui.c	Thu Dec 27 06:00:20 2001
+++ src/gui.c	Thu Dec 27 06:01:59 2001
@@ -16,7 +16,7 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 #include <gtk/gtk.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "auxil.h"
 #include "character.h"
Common subdirectories: src.dist/pixmaps and src/pixmaps
diff -u src.dist/raster_font.c src/raster_font.c
--- src.dist/raster_font.c	Thu Dec 27 06:00:20 2001
+++ src/raster_font.c	Thu Dec 27 06:01:59 2001
@@ -15,7 +15,7 @@
  * along with this program; if not, write to the Free Software
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "auxil.h"
 #include "bitmap.h"
diff -u src.dist/raster_glyph.c src/raster_glyph.c
--- src.dist/raster_glyph.c	Thu Dec 27 06:00:20 2001
+++ src/raster_glyph.c	Thu Dec 27 06:01:59 2001
@@ -17,7 +17,7 @@
  */
 #include <gtk/gtk.h>
 
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "bitmap.h"
 #include "font.h"
