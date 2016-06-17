Only in src.dist: about_dialog.o
--- src/auxil.c.orig	2000-06-27 07:19:31 UTC
+++ src/auxil.c
@@ -16,7 +16,7 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 #include <ctype.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <gtk/gtk.h>
 
 #include "auxil.h"
--- src/bitmap.c.orig	2000-06-27 07:19:31 UTC
+++ src/bitmap.c
@@ -16,7 +16,7 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 #include <gtk/gtk.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "bitmap.h"
 
--- src/file.c.orig	2000-07-03 05:43:15 UTC
+++ src/file.c
@@ -16,7 +16,7 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 #include <gtk/gtk.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "auxil.h"
 #include "bdf.h"
--- src/font.c.orig	2000-06-27 07:19:31 UTC
+++ src/font.c
@@ -16,7 +16,7 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 #include <gtk/gtk.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "auxil.h"
 #include "font.h"
--- src/glyph.c.orig	2000-06-27 07:19:31 UTC
+++ src/glyph.c
@@ -16,7 +16,7 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 #include <gtk/gtk.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "auxil.h"
 #include "glyph.h"
--- src/gui.c.orig	2000-06-29 15:33:23 UTC
+++ src/gui.c
@@ -16,7 +16,7 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 #include <gtk/gtk.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "auxil.h"
 #include "character.h"
--- src/raster_font.c.orig	2000-06-27 07:19:31 UTC
+++ src/raster_font.c
@@ -15,7 +15,7 @@
  * along with this program; if not, write to the Free Software
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "auxil.h"
 #include "bitmap.h"
--- src/raster_glyph.c.orig	2000-06-27 07:19:31 UTC
+++ src/raster_glyph.c
@@ -17,7 +17,7 @@
  */
 #include <gtk/gtk.h>
 
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "bitmap.h"
 #include "font.h"
