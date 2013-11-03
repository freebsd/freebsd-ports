--- ./packages/swi-minisat2/C/SolverTypes.h.orig	2010-10-18 06:48:21.000000000 -0200
+++ ./packages/swi-minisat2/C/SolverTypes.h	2013-11-02 21:10:56.000000000 -0200
@@ -119,11 +119,7 @@
 
     // -- use this function instead:
     template<class V>
-    friend Clause* Clause_new(const V& ps, bool learnt = false) {
-        assert(sizeof(Lit)      == sizeof(uint32_t));
-        assert(sizeof(float)    == sizeof(uint32_t));
-        void* mem = malloc(sizeof(Clause) + sizeof(uint32_t)*(ps.size()));
-        return new (mem) Clause(ps, learnt); }
+    friend Clause* Clause_new(const V& ps, bool learnt = false);
 
     int          size        ()      const   { return size_etc >> 3; }
     void         shrink      (int i)         { assert(i <= size()); size_etc = (((size_etc >> 3) - i) << 3) | (size_etc & 7); }
@@ -146,6 +142,14 @@
     void         strengthen  (Lit p);
 };
 
+template<class V>
+Clause* Clause_new(const V& ps, bool learnt) {
+    assert(sizeof(Lit)      == sizeof(uint32_t));
+    assert(sizeof(float)    == sizeof(uint32_t));
+    void* mem = malloc(sizeof(Clause) + sizeof(uint32_t)*(ps.size()));
+    return new (mem) Clause(ps, learnt);
+}
+
 
 /*_________________________________________________________________________________________________
 |
