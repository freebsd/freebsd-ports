--- lib/misc/strlist.cc.orig	Mon Feb  2 14:38:26 2004
+++ lib/misc/strlist.cc	Mon Feb  2 14:38:45 2004
@@ -15,6 +15,7 @@
 // Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 
 #include <config.h>
+#include <string.h>
 #include "strlist.h"
 
 static const char* compare(const char* ptr, const char* end,
