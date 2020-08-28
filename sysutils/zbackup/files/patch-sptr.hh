--- sptr.hh.orig	2015-09-16 07:28:04 UTC
+++ sptr.hh
@@ -25,9 +25,9 @@ class sptr_base
 
 public:
 
-  sptr_base(): p( 0 ), count( 0 ) {}
+  sptr_base(): p( nullptr ), count( nullptr ) {}
 
-  sptr_base( T * p_ ): p( p_ ), count( p ? new unsigned( 1 ) : 0 )
+  sptr_base( T * p_ ): p( p_ ), count( p ? new unsigned( 1 ) : nullptr )
   {
   }
 
@@ -48,27 +48,27 @@ class sptr_base
       {
         delete count;
 
-        count = 0;
+        count = nullptr;
 
         if ( p )
         {
           T * p_ = p;
   
-          p = 0;
+          p = nullptr;
   
           delete p_;
         }
       }
       else
       {
-        p = 0;
-        count = 0;
+        p = nullptr;
+        count = nullptr;
       }
     }
   }
 
   unsigned use_count() const
-  { return count; }
+  { return *count; }
 
   sptr_base & operator = ( sptr_base const & other )
   { if ( &other != this ) { reset(); p = other.p; count = other.count; increment(); }
