Index: utils.c
diff -u utils.c:1.1.1.1 utils.c:1.1.1.1.4.1
--- utils.c:1.1.1.1	Sun Feb  4 12:58:55 2001
+++ utils.c	Sat Feb 17 17:07:51 2001
@@ -40,6 +40,9 @@
 #include "plugins.h"
 #include "libplugin.h"
 
+#include "japanese.h"
+#include "cp1250.h"
+#include "russian.h"
 
 #include <pi-source.h>
 #include <pi-socket.h>
@@ -1981,7 +1984,7 @@
        char *p, *q;
        int n = 0;
        p = src; q = dst;
-       while ((*p) && n < (max_len-1)) {
+       while ((*p) && n < (max_len-2)) {
 	   if ((*p) & 0x80) {
 	       *q++ = *p++;
 	       n++;
@@ -1994,11 +1997,10 @@
 	       n++;
 	   }
        }
-       if ((*p & 0x80 ) && (n < max_len)) {
-	   *q = *p;
-       } else {
-	   *q = '\0';
-       }
+       if (!(*p & 0x80 ) && (n < max_len-1))
+	       *q++ = *p++;
+
+       *q = '\0';
    } else {
       strncpy(dst, src, max_len);
    }
@@ -2022,7 +2024,7 @@
       int n = 0;
 
       p = (char *)src; q = dst;
-      while ((*p) && (n < (len -1))) {
+      while ((*p) && (n < (len -2))) {
         if ((*p) & 0x80) {
 	   *q++ = *p++;
 	   n++;
@@ -2033,15 +2035,15 @@
         } else {
 	   *q++ = *p++;
 	   n++;
+	   if (*(p-1) == (char)(c & 0xff)) return q;
 	}
-        if (*(p-1) == (char)(c & 0xff)) return q;
-      }
-      if ((*p & 0x80) && (n < len)) {
-         *q = *p;
-      } else {
- 	 *q = '\0';
       }
+      if (!(*p & 0x80) && (n < len-1)) 
+	      *q++ = *p++;
+
+      *q = '\0';
       return NULL; 
    } else
       return memccpy(dst, src, c, len);
 }
+
