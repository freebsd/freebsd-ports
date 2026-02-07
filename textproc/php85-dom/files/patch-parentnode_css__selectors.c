--- parentnode/css_selectors.c.orig	2025-07-02 12:24:35 UTC
+++ parentnode/css_selectors.c
@@ -23,7 +23,7 @@
 #include "../php_dom.h"
 #include "../obj_map.h"
 
-#include "ext/lexbor/lexbor/css/parser.h"
+#include "lexbor/css/parser.h"
 #include "../lexbor/selectors-adapted/selectors.h"
 
 // TODO: optimization idea: cache the parsed selectors in an LRU fashion?
