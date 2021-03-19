--- ebtree/ebtree.h.orig	2021-03-19 17:56:33.131201000 +0000
+++ ebtree/ebtree.h	2021-03-19 17:54:50.584874000 +0000
@@ -247,6 +247,7 @@
 #define _EBTREE_H
 
 #include <stdlib.h>
+#include <unistd.h>
 #include "compiler.h"
 
 static inline int flsnz8_generic(unsigned int x)
