--- src/RandLM/RandLMTypes.h.orig	2014-09-01 18:20:25.000000000 +0400
+++ src/RandLM/RandLMTypes.h	2014-09-01 18:21:06.000000000 +0400
@@ -21,7 +21,7 @@
 #include <string>
 #include <stdint.h>
 
-#define iterate(c,i) for(typeof(c.begin()) i = c.begin(); i != c.end(); i++)
+#define iterate(c,i) for(auto i = c.begin(); i != c.end(); i++)
 
 namespace randlm {
 
