--- src/SharedFileList.cpp.orig	Sun Mar 23 01:02:07 2003
+++ src/SharedFileList.cpp	Sun Mar 23 01:02:34 2003
@@ -15,6 +15,10 @@
 //along with this program; if not, write to the Free Software
 //Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 //#include "stdafx.h"
 #include "emule.h"
 #include "emuleDlg.h"
@@ -28,6 +32,10 @@
 #include "ED2KLink.h"
 #include "packets.h"
 #include <time.h>
+
+#if (defined(BSD) && (BSD >= 199103))
+#include <libgen.h>
+#endif
 
 CSharedFileList::CSharedFileList(CPreferences* in_prefs,CServerConnect* in_server,CKnownFileList* in_filelist){
 	app_prefs = in_prefs;
