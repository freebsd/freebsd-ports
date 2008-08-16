--- stlhelp.h	2004-05-29 16:00:08.000000000 -0700
+++ stlhelp.h	2008-03-02 23:03:02.000000000 -0800
@@ -19,6 +19,8 @@
 #ifndef _STLHELP_H_
 #define _STLHELP_H_
 
+#include <string.h>
+
 struct eqstr
 {
 	bool operator()(const char* s1, const char* s2) const
