--- src/mozilla/kz-mozembed.cpp.orig	Tue Feb  8 22:01:07 2005
+++ src/mozilla/kz-mozembed.cpp	Tue Feb  8 22:01:23 2005
@@ -64,7 +64,11 @@
 #include <docshell/nsIDocShellTreeItem.h>
 #include <docshell/nsIDocShellTreeOwner.h>
 #include <nsIPresShell.h>
+#if MOZILLA_SNAPSHOT > 16
+#include <nsPresContext.h>
+#else
 #include <nsIPresContext.h>
+#endif
 #include <nsIDOMNodeList.h>
 #include <nsIDOMWindow.h>
 #include <nsISelection.h>
