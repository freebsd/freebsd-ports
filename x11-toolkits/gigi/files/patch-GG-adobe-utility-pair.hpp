--- GG/adobe/utility/pair.hpp.orig	2009-04-17 07:55:09.000000000 +0400
+++ GG/adobe/utility/pair.hpp	2012-01-27 19:33:57.000000000 +0300
@@ -79,11 +79,11 @@
     
     pair() : first(), second() { }
     
-    pair(move_from<pair> x) : first(move(x.source.first)), second(move(x.source.second)) { }
+  pair(move_from<pair> x) : first(::adobe::move(x.source.first)), second(::adobe::move(x.source.second)) { }
     
-    pair& operator=(pair x) { first = move(x.first); second = move(x.second); return *this; }
+  pair& operator=(pair x) { first = ::adobe::move(x.first); second = ::adobe::move(x.second); return *this; }
     
-    pair(T1 x, T2 y) : first(move(x)), second(move(y)) { }
+  pair(T1 x, T2 y) : first(::adobe::move(x)), second(::adobe::move(y)) { }
     
     template <typename U1, typename U2>
     pair(const pair<U1, U2>& p) : first(p.first), second(p.second) { }
