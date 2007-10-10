--- src/fco/fcosetimpl.h.orig	2005-09-15 20:12:38.000000000 -0700
+++ src/fco/fcosetimpl.h	2007-10-09 23:52:30.000000000 -0700
@@ -46,6 +46,8 @@
 #include "fconame.h"
 #endif
 
+class cFCOIterImpl;
+
 class cFCOSetImpl : public iFCOSet
 {
 	friend class cFCOIterImpl;
