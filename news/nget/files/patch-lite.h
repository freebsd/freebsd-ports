--- lite.h	2004-05-29 16:00:08.000000000 -0700
+++ lite.h	2008-03-02 23:03:01.000000000 -0800
@@ -24,6 +24,8 @@
 #endif
 
 #include <stdlib.h>
+#include <string.h>
+
 char * newstrcpy(char *&dest, const char *src);
 inline void safefree(char *&p){
     if (p){free(p);p=NULL;}
