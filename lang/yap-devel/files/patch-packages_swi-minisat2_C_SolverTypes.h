https://sourceforge.net/p/yap/yap-6.3/ci/6d2e2597b183

--- packages/swi-minisat2/C/SolverTypes.h.orig	2012-06-29 21:30:38 UTC
+++ packages/swi-minisat2/C/SolverTypes.h
@@ -119,7 +119,7 @@ public:
 
     // -- use this function instead:
     template<class V>
-    friend Clause* Clause_new(const V& ps, bool learnt = false);
+    friend Clause* Clause_new(const V& ps, bool learnt);
 
     int          size        ()      const   { return size_etc >> 3; }
     void         shrink      (int i)         { assert(i <= size()); size_etc = (((size_etc >> 3) - i) << 3) | (size_etc & 7); }
