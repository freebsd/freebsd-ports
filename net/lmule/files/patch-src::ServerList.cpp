--- src/ServerList.cpp.orig	Sun Mar 23 00:12:47 2003
+++ src/ServerList.cpp	Sun Mar 23 00:13:13 2003
@@ -15,6 +15,9 @@
 //along with this program; if not, write to the Free Software
 //Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
 
 //#include "stdafx.h"
 #include "ServerList.h"
@@ -346,7 +349,12 @@
 
 #include <wx/txtstrm.h>
 #include <wx/wfstream.h>
+
+#if (defined(BSD) && (BSD >= 199103))
+#define MAX_PATH MAXPATHLEN
+#else
 #define MAX_PATH 1024
+#endif
 
 void CServerList::AddServersFromTextFile(CString strFilename,bool isstaticserver) {
 	wxString strLine;
