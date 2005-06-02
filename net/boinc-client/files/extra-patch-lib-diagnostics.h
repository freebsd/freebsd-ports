--- lib/diagnostics.h.orig	Fri Mar 25 07:51:07 2005
+++ lib/diagnostics.h	Thu Jun  2 08:43:04 2005
@@ -149,7 +149,7 @@
 #else  // _DEBUG
 
 #define BOINCASSERT(expr)         
-#define BOINCTRACE(...)          
+#define BOINCTRACE
 #define BOINCINFO           boinc_info_release
 
 #endif // _DEBUG
