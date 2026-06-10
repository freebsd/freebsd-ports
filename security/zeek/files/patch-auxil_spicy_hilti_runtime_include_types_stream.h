--- auxil/spicy/hilti/runtime/include/types/stream.h.orig	2026-05-12 18:14:47 UTC
+++ auxil/spicy/hilti/runtime/include/types/stream.h
@@ -691,7 +691,7 @@ class SafeConstIterator { (private)
 
     void _ensureValidChain() const {
         // This must have been checked at this point already.
-        assert(_chain);
+        assert(_chain.get());
 
         if ( ! _chain->isValid() )
             throw InvalidIterator("stream object no longer available");
@@ -1752,7 +1752,7 @@ class Stream { (public)
 
     /** Destructor. */
     ~Stream() {
-        assert(_chain);
+        assert(_chain.get());
         _chain->invalidate();
     }
 
