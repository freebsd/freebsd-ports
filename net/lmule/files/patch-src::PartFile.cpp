--- src/PartFile.cpp.orig	Sun Mar 23 00:11:08 2003
+++ src/PartFile.cpp	Sun Mar 23 00:12:13 2003
@@ -14,6 +14,10 @@
 //along with this program; if not, write to the Free Software
 //Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #include "PartFile.h"
 #include "emule.h"
 #include "updownclient.h"
@@ -177,7 +181,11 @@
 		delete gaplist.GetAt(pos);
 }
 
+#if (defined(BSD) && (BSD >= 199103))
+#define MAX_PATH MAXPATHLEN
+#else
 #define MAX_PATH 1024
+#endif
 
 void CPartFile::CreatePartFile(){
 	// use lowest free partfilenumber for free file (InterCeptor)
