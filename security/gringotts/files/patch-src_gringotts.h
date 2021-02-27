--- src/gringotts.h.orig	2008-09-01 16:20:06 UTC
+++ src/gringotts.h
@@ -24,10 +24,10 @@
 
 #include "grg_defs.h"
 
-GList *garbage;
+extern GList *garbage;
 
-GRG_CTX gctx;
-glong pwdbirth;
+extern GRG_CTX gctx;
+extern glong pwdbirth;
 
 	/*callbacks for menu items */
 
