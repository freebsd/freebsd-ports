--- src/kernel/gmp++/gmp++_int.h.orig	2019-06-07 13:23:45 UTC
+++ src/kernel/gmp++/gmp++_int.h
@@ -234,6 +234,7 @@ namespace Givaro {
          */
         ///@{
         giv_all_inlined Integer& operator = (const Integer& n);
+        giv_all_inlined Integer& operator = (const Integer& n) const;
         giv_all_inlined Integer& logcpy(const Integer& n);
         giv_all_inlined Integer& copy(const Integer& n);
         ///@}
