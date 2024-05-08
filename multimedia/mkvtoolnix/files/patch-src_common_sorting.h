--- src/common/sorting.h.orig	2024-04-28 10:37:21 UTC
+++ src/common/sorting.h
@@ -27,7 +27,7 @@ template<  typename Titer
 
 template<  typename Titer
          , typename Tcriterion_maker
-         , typename Tcriterion = typename std::result_of< Tcriterion_maker(typename std::iterator_traits<Titer>::value_type) >::type
+         , typename Tcriterion = typename std::invoke_result< Tcriterion_maker, typename std::iterator_traits<Titer>::value_type >::type
          , typename Tcomparator = std::less<Tcriterion>
          >
 void
