diff --git a/src/lzw/ftzopen.c b/src/lzw/ftzopen.c
index fc78315..c0483de 100644
--- src/lzw/ftzopen.c
+++ src/lzw/ftzopen.c
@@ -332,6 +332,9 @@
 
           while ( code >= 256U )
           {
+            if ( !state->prefix )
+              goto Eof;
+
             FTLZW_STACK_PUSH( state->suffix[code - 256] );
             code = state->prefix[code - 256];
           }
