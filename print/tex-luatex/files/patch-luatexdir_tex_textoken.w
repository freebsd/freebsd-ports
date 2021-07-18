--- luatexdir/tex/textoken.w.orig	2015-03-28 00:34:27 UTC
+++ luatexdir/tex/textoken.w
@@ -75,7 +75,7 @@ maximum memory usage. When code between the delimiters
 report these statistics when |tracing_stats| is sufficiently large.
 
 @c
-int var_used, dyn_used;         /* how much memory is in use */
+int dyn_used;                   /* how much memory is in use */
 
 halfword avail;                 /* head of the list of available one-word nodes */
 unsigned fix_mem_end;           /* the last one-word node used in |mem| */
