--- avl.h.orig	Thu Oct 29 02:25:09 1998
+++ avl.h	Mon Jul  2 16:47:44 2007
@@ -44,7 +44,11 @@
 } avlTree;
 
 #define AVL_LINK(a,N)            (((a) == -1) ? (N)->left : (N)->right)
-#define AVL_LINK_SET(s,P,V)      ((((s) == -1) ? (P)->left : (P)->right) = (V))
+#define AVL_LINK_SET(s,P,V) \
+	do { \
+		typeof (V) foo = (((s) == -1) ? (P)->left : (P)->right); \
+		foo = (V); \
+	} while (0)
 
 int avlCompare (avlTree*, void*, unsigned int, avlNode*);
 int avlBalance (avlNode*, int, avlNode**);
