--- hparser.c.orig	Fri Feb 10 09:28:37 2006
+++ hparser.c	Fri Feb 10 09:28:57 2006
@@ -135,16 +135,16 @@ report_event(PSTATE* p_state,
     #define CHR_DIST(a,b) ((a) - (b))
 #endif
 
+    /* capture offsets */
+    STRLEN offset = p_state->offset;
+    STRLEN line = p_state->line;
+    STRLEN column = p_state->column;
+
     /* some events might still fire after a handler has signaled eof
      * so suppress them here.
      */
     if (p_state->eof)
 	return;
-
-    /* capture offsets */
-    STRLEN offset = p_state->offset;
-    STRLEN line = p_state->line;
-    STRLEN column = p_state->column;
 
 #if 0
     {  /* used for debugging at some point */
