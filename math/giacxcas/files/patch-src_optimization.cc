PARI's paridecl.h declares a global function `bitset(GEN x, long n)`.
Since optimization.cc does `using namespace std;` and PARI headers are
pulled in transitively, the unqualified use of `bitset<32>` becomes
ambiguous between `::bitset` (PARI) and `std::bitset`. Qualify it
explicitly to resolve the ambiguity.

--- src/optimization.cc.orig
+++ src/optimization.cc
@@ -1271,7 +1271,7 @@
     vector<ulong> sets(comb(n,m).val);
     int i=0;
     for (ulong k=1;k<N;++k) {
-        bitset<32> b(k);
+        std::bitset<32> b(k);
         if (b.count()==(size_t)m)
             sets[i++]=k;
     }
