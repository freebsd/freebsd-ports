--- ./authenticate/authvmailmgr.cc.orig	Mon Feb  2 14:45:25 2004
+++ ./authenticate/authvmailmgr.cc	Mon Feb  2 14:45:40 2004
@@ -15,6 +15,7 @@
 // Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 
 #include <config.h>
+#include <string.h>
 #include "misc/exec.h"
 #include "authvlib.h"
 // Courier-IMAP includes
