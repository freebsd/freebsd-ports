--- src/Core/gnu/ACG.cc.orig	2002-03-27 12:32:59.000000000 +0100
+++ src/Core/gnu/ACG.cc
@@ -123,7 +123,7 @@ static int randomStateTable[][3] = {
 //
 
 #define RANDOM_PERM_SIZE 64
-_G_uint32_t randomPermutations[RANDOM_PERM_SIZE] = {
+uint32_t randomPermutations[RANDOM_PERM_SIZE] = {
 0xffffffff, 0x00000000,  0x00000000,  0x00000000,  // 3210
 0x0000ffff, 0x00ff0000,  0x00000000,  0xff000000,  // 2310
 0xff0000ff, 0x0000ff00,  0x00000000,  0x00ff0000,  // 3120
@@ -149,7 +149,7 @@ _G_uint32_t randomPermutations[RANDOM_PE
 //	SEED_TABLE_SIZE must be a power of 2
 //
 #define SEED_TABLE_SIZE 32
-static _G_uint32_t seedTable[SEED_TABLE_SIZE] = {
+static uint32_t seedTable[SEED_TABLE_SIZE] = {
 0xbdcc47e5, 0x54aea45d, 0xec0df859, 0xda84637b,
 0xc8c6cb4f, 0x35574b01, 0x28260b7d, 0x0d07fdbf,
 0x9faaeeb0, 0x613dd169, 0x5ce2d818, 0x85b9e706,
@@ -171,15 +171,15 @@ static _G_uint32_t seedTable[SEED_TABLE_
 // LC_C = result of a long trial & error series = 3907864577
 //
 
-static const _G_uint32_t LC_A = 66049;
-static const _G_uint32_t LC_C = 3907864577u;
-static inline _G_uint32_t LCG(_G_uint32_t x)
+static const uint32_t LC_A = 66049;
+static const uint32_t LC_C = 3907864577u;
+static inline uint32_t LCG(uint32_t x)
 {
     return( x * LC_A + LC_C );
 }
 
 
-ACG::ACG(_G_uint32_t seed, int size)
+ACG::ACG(uint32_t seed, int size)
 {
     register int l;
     initialSeed = seed;
@@ -205,7 +205,7 @@ ACG::ACG(_G_uint32_t seed, int size)
     //	Allocate the state table & the auxillary table in a single malloc
     //
     
-    state = new _G_uint32_t[stateSize + auxSize];
+    state = new uint32_t[stateSize + auxSize];
     auxState = &state[stateSize];
 
     reset();
@@ -217,7 +217,7 @@ ACG::ACG(_G_uint32_t seed, int size)
 void
 ACG::reset()
 {
-    register _G_uint32_t u;
+    register uint32_t u;
 
     if (initialSeed < SEED_TABLE_SIZE) {
 	u = seedTable[ initialSeed ];
@@ -247,7 +247,7 @@ ACG::reset()
     
     lcgRecurr = u;
     
-    assert(sizeof(double) == 2 * sizeof(_G_int32_t));
+    assert(sizeof(double) == 2 * sizeof(int32_t));
 }
 
 ACG::~ACG()
@@ -261,16 +261,16 @@ ACG::~ACG()
 //	Returns 32 bits of random information.
 //
 
-_G_uint32_t
+uint32_t
 ACG::asLong()
 {
-    _G_uint32_t result = state[k] + state[j];
+    uint32_t result = state[k] + state[j];
     state[k] = result;
     j = (j <= 0) ? (stateSize-1) : (j-1);
     k = (k <= 0) ? (stateSize-1) : (k-1);
     
     short int auxIndex = (result >> 24) & (auxSize - 1);
-    register _G_uint32_t auxACG = auxState[auxIndex];
+    register uint32_t auxACG = auxState[auxIndex];
     auxState[auxIndex] = lcgRecurr = LCG(lcgRecurr);
     
     //
@@ -278,7 +278,7 @@ ACG::asLong()
     // do not want to run off the end of the permutation table.
     // This insures that we have always got four entries left.
     //
-    register _G_uint32_t *perm = & randomPermutations[result & 0x3c];
+    register uint32_t *perm = & randomPermutations[result & 0x3c];
     
     result =  *(perm++) & auxACG;
     result |= *(perm++) & ((auxACG << 24)
