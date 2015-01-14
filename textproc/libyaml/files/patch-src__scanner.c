--- src/scanner.c.orig	2014-03-27 03:54:02.000000000 +0900
+++ src/scanner.c	2014-12-14 10:07:35.636167929 +0900
@@ -1106,13 +1106,6 @@
             && parser->indent == (ptrdiff_t)parser->mark.column);
 
     /*
-     * A simple key is required only when it is the first token in the current
-     * line.  Therefore it is always allowed.  But we add a check anyway.
-     */
-
-    assert(parser->simple_key_allowed || !required);    /* Impossible. */
-
-    /*
      * If the current position may start a simple key, save it.
      */
 
