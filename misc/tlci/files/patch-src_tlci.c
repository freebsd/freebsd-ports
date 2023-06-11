--- src/tlci.c.orig	2023-06-11 19:01:46 UTC
+++ src/tlci.c
@@ -46,7 +46,7 @@ extern void switch_to_stdin(void);
 extern FILE* yyin;
 
 /*********************************************************************************/
-static void on_quit()
+static void on_quit(void)
 {
     heap_destroy(tlci_heap);
 }
