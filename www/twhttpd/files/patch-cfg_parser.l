--- cfg_parser.l.orig	Sun Feb  4 20:01:24 2007
+++ cfg_parser.l	Sun Feb  4 20:11:01 2007
@@ -22,7 +22,9 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, 
  * MA  02111-1307, USA.
  */
-  
+
+#include <string.h>
+
 #include   "y.tab.h"
 
 int        yylineno=1;
