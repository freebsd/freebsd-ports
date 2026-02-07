https://sourceforge.net/p/yap/yap-6.3/ci/e938c1774890
https://sourceforge.net/p/yap/yap-6.3/ci/6d2e2597b183

--- packages/swi-minisat2/C/SolverTypes.h.orig	2010-10-18 08:48:21 UTC
+++ packages/swi-minisat2/C/SolverTypes.h
@@ -119,11 +119,7 @@ public:
 
     // -- use this function instead:
     template<class V>
-    friend Clause* Clause_new(const V& ps, bool learnt = false) {
-        assert(sizeof(Lit)      == sizeof(uint32_t));
-        assert(sizeof(float)    == sizeof(uint32_t));
-        void* mem = malloc(sizeof(Clause) + sizeof(uint32_t)*(ps.size()));
-        return new (mem) Clause(ps, learnt); }
+    friend Clause* Clause_new(const V& ps, bool learnt);
 
     int          size        ()      const   { return size_etc >> 3; }
     void         shrink      (int i)         { assert(i <= size()); size_etc = (((size_etc >> 3) - i) << 3) | (size_etc & 7); }
@@ -147,6 +143,12 @@ public:
 };
 
 
+template<class V>
+Clause* Clause_new(const V& ps, bool learnt) {
+        assert(sizeof(Lit)      == sizeof(uint32_t));
+        assert(sizeof(float)    == sizeof(uint32_t));
+        void* mem = malloc(sizeof(Clause) + sizeof(uint32_t)*(ps.size()));
+        return new (mem) Clause(ps, learnt); }
 /*_________________________________________________________________________________________________
 |
 |  subsumes : (other : const Clause&)  ->  Lit
