--- sptr.hh.orig	2020-11-23 20:39:45 UTC
+++ sptr.hh
@@ -67,9 +67,6 @@ class sptr_base (public)
     }
   }
 
-  unsigned use_count() const
-  { return count; }
-
   sptr_base & operator = ( sptr_base const & other )
   { if ( &other != this ) { reset(); p = other.p; count = other.count; increment(); }
     return * this; }
