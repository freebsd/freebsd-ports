--- src/Core/gnu/MLCG.h.orig	2002-03-27 12:32:59.000000000 +0100
+++ src/Core/gnu/MLCG.h
@@ -29,55 +29,55 @@ Foundation, 59 Temple Place - Suite 330,
 //
 
 class MLCG : public RNG {
-    _G_int32_t initialSeedOne;
-    _G_int32_t initialSeedTwo;
-    _G_int32_t seedOne;
-    _G_int32_t seedTwo;
+    int32_t initialSeedOne;
+    int32_t initialSeedTwo;
+    int32_t seedOne;
+    int32_t seedTwo;
 
 protected:
 
 public:
-    MLCG(_G_int32_t seed1 = 0, _G_int32_t seed2 = 1);
+    MLCG(int32_t seed1 = 0, int32_t seed2 = 1);
     //
     // Return a long-words word of random bits
     //
-    virtual _G_uint32_t asLong();
+    virtual uint32_t asLong();
     virtual void reset();
-    _G_int32_t seed1();
-    void seed1(_G_int32_t);
-    _G_int32_t seed2();
-    void seed2(_G_int32_t);
-    void reseed(_G_int32_t, _G_int32_t);
+    int32_t seed1();
+    void seed1(int32_t);
+    int32_t seed2();
+    void seed2(int32_t);
+    void reseed(int32_t, int32_t);
 };
 
-inline _G_int32_t
+inline int32_t
 MLCG::seed1()
 {
     return(seedOne);
 }
 
 inline void
-MLCG::seed1(_G_int32_t s)
+MLCG::seed1(int32_t s)
 {
     initialSeedOne = s;
     reset();
 }
 
-inline _G_int32_t
+inline int32_t
 MLCG::seed2()
 {
     return(seedTwo);
 }
 
 inline void
-MLCG::seed2(_G_int32_t s)
+MLCG::seed2(int32_t s)
 {
     initialSeedTwo = s;
     reset();
 }
 
 inline void
-MLCG::reseed(_G_int32_t s1, _G_int32_t s2)
+MLCG::reseed(int32_t s1, int32_t s2)
 {
     initialSeedOne = s1;
     initialSeedTwo = s2;
