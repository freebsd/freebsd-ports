--- lib/misc/keystrlist.cc.orig	Mon Feb  2 14:33:33 2004
+++ lib/misc/keystrlist.cc	Mon Feb  2 14:33:55 2004
@@ -15,6 +15,7 @@
 // Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 
 #include <config.h>
+#include <string.h>
 #include "strlist.h"
 
 void keystrlist::set(const mystring& var, const mystring& val)
