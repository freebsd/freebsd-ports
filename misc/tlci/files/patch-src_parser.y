--- src/parser.y.orig	2023-06-11 19:00:49 UTC
+++ src/parser.y
@@ -4,7 +4,7 @@
 #include <tlci/heap.h>
 #include <tlci/string.h>
 extern heap_t* tlci_heap;
-extern int yylex();
+extern int yylex(void);
 extern void yyerror(const char*);
 #define mkAP(f, a) \
     heap_alloc_ap(tlci_heap, f, a)
