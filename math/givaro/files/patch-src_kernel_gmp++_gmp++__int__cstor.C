--- src/kernel/gmp++/gmp++_int_cstor.C.orig	2019-06-07 13:23:45 UTC
+++ src/kernel/gmp++/gmp++_int_cstor.C
@@ -105,6 +105,11 @@ namespace Givaro {
         return logcpy(n) ;
     }
 
+    Integer& Integer::operator = (const Integer &n) const
+    {
+        return const_cast<Integer*>(this)->logcpy(n) ;
+    }
+
 
     Integer& Integer::copy(const Integer &n)
     {
