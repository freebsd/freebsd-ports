--- include/macros.h.orig	Sat Jul 19 05:53:50 2003
+++ include/macros.h	Thu Jul  5 05:45:33 2007
@@ -103,9 +103,10 @@
 /*
 this macro will shift a node in a linked list up or down one
 */
-#define SHIFTNODE(t, x, a, d) { \
+#define SHIFTNODE(t, _x, a, d) { \
 	do { \
 		t tmp_node = NULL; \
+		t x = _x; \
 		if (d == UP && a != (x)) { \
 			if ((x) == a->prev) (x) = a; \
 			if (a->prev->prev != NULL) a->prev->prev->next = a; \
@@ -131,9 +132,10 @@
 /*
 this macro moves a list node to top or bottom of list
 */
-#define SETNODE(t, x, a, d) { \
+#define SETNODE(t, _x, a, d) { \
 	do { \
 		t tmp_node = NULL; \
+		t x = _x; \
 		if (d == TOP && a != (x)) { \
 			if (a->next != NULL) a->next->prev = a->prev; \
 			a->prev->next = a->next; \
