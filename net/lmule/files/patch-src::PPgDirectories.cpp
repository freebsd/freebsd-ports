--- src/PPgDirectories.cpp.orig	Sun Mar 23 00:10:03 2003
+++ src/PPgDirectories.cpp	Sun Mar 23 00:10:42 2003
@@ -1,6 +1,10 @@
 // PPgDirectories.cpp : implementation file
 //
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 //#include "stdafx.h"
 #include "wintypes.h"
 #include "emule.h"
@@ -13,7 +17,11 @@
 #include "wx/xrc/xmlres.h"
 #include "wx/xrc/xh_all.h"
 
+#if (defined(BSD) && (BSD >= 199103))
+#define MAX_PATH MAXPATHLEN
+#else
 #define MAX_PATH 2048
+#endif
 
 #define GetDlgItem(x,clas) XRCCTRL(*this,#x,clas)
 #define IsDlgButtonChecked(x) XRCCTRL(*this,#x,wxCheckBox)->GetValue()
