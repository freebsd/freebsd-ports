--- third_party/openfst/src/include/fst/replace.h.orig	2018-10-14 23:15:07 UTC
+++ third_party/openfst/src/include/fst/replace.h
@@ -1250,7 +1250,7 @@ class ArcIterator< ReplaceFst<A, T, C> > {
     // If state is already cached, use cached arcs array.
     if (fst_.GetImpl()->HasArcs(state_)) {
       (fst_.GetImpl())
-          ->template CacheBaseImpl<typename C::State, C>::InitArcIterator(
+          ->CacheBaseImpl<typename C::State, C>::InitArcIterator(
               state_, &cache_data_);
       num_arcs_ = cache_data_.narcs;
       arcs_ = cache_data_.arcs;      // 'arcs_' is a ptr to the cached arcs.
