--- kernel/sources/kr_mem.c.orig	Sat Sep 28 20:55:39 2002
+++ kernel/sources/kr_mem.c	Sat Sep 28 20:56:45 2002
@@ -26,6 +26,7 @@
 #include <values.h>
 #else
 #include <math.h>
+#include <limits.h>
 #endif
 
 
@@ -1023,7 +1024,7 @@
 
   if ( (n_ptr = krm_NTableSymbolSearch( symbol_name, symbol_type ) ) != NULL)
     {   /*  symbol is already in the name table  */
-    if ((n_ptr->ref_count) < ((unsigned short) MAXSHORT)) {
+    if ((n_ptr->ref_count) < ((unsigned short) SHRT_MAX)) {
         n_ptr->ref_count++;
     }
     return( n_ptr->Entry.symbol );
@@ -1052,7 +1053,7 @@
   if (symbol_name == NULL)  return;
   if ( (n_ptr = krm_NTableSymbolSearch( symbol_name, symbol_type ) ) != NULL)
     {   /*  symbol is in the name table  */
-    if ((n_ptr->ref_count) < ((unsigned short) MAXSHORT))
+    if ((n_ptr->ref_count) < ((unsigned short) SHRT_MAX))
       {   /*    No. of references to this symbol don't exceed the max. reference
                 count. This means it is possible to delete the symbol if the
                 reference count is zero.
