--- src/npupp.h.orig	2014-01-03 17:14:34.000000000 +0100
+++ src/npupp.h	2014-10-25 18:16:23.746171118 +0200
@@ -63,6 +63,9 @@
 
 #include "npruntime.h"
 
+#ifndef NP_LOADDS
+#define NP_LOADDS
+#endif
 
 /******************************************************************************************
    plug-in function table macros
