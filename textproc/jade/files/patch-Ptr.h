--- include/Ptr.h.orig	Wed Oct  7 14:15:50 1998
+++ include/Ptr.h	Tue Jul 22 09:19:49 2003
@@ -5,6 +5,7 @@
 #define Ptr_INCLUDED 1
 
 #include "Boolean.h"
+#include "Resource.h"
 
 // T must have Resource as a public base class
 // T may be an incomplete type
