--- src/libxml/node_manip.cxx.orig	Wed Nov 19 08:08:59 2003
+++ src/libxml/node_manip.cxx	Sat Mar 20 02:17:06 2004
@@ -39,6 +39,7 @@
 #include "node_manip.h"
 
 // standard includes
+#include <new>
 #include <stdexcept>
 
 // libxml includes
