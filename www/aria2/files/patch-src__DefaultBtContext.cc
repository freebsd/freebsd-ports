--- ./src/DefaultBtContext.cc.orig	Wed Nov 29 20:58:04 2006
+++ ./src/DefaultBtContext.cc	Wed Nov 29 20:58:13 2006
@@ -40,6 +40,7 @@
 #include "DlAbortEx.h"
 #include "ShaVisitor.h"
 #include "Util.h"
+#include <libgen.h>
 
 DefaultBtContext::DefaultBtContext() {}
 
