--- src/Core/gnu/MLCG.cc.orig	2002-03-27 12:32:59.000000000 +0100
+++ src/Core/gnu/MLCG.cc
@@ -25,7 +25,7 @@ Foundation, 59 Temple Place - Suite 330,
 
 #define SEED_TABLE_SIZE 32
 
-static _G_int32_t seedTable[SEED_TABLE_SIZE] = {
+static int32_t seedTable[SEED_TABLE_SIZE] = {
 0xbdcc47e5, 0x54aea45d, 0xec0df859, 0xda84637b,
 0xc8c6cb4f, 0x35574b01, 0x28260b7d, 0x0d07fdbf,
 0x9faaeeb0, 0x613dd169, 0x5ce2d818, 0x85b9e706,
@@ -36,7 +36,7 @@ static _G_int32_t seedTable[SEED_TABLE_S
 0xb89cff2b, 0x12164de1, 0xa865168d, 0x32b56cdf
 };
 
-MLCG::MLCG(_G_int32_t seed1, _G_int32_t seed2)
+MLCG::MLCG(int32_t seed1, int32_t seed2)
 {
     initialSeedOne = seed1;
     initialSeedTwo = seed2;
@@ -46,8 +46,8 @@ MLCG::MLCG(_G_int32_t seed1, _G_int32_t 
 void
 MLCG::reset()
 {
-    _G_int32_t seed1 = initialSeedOne;
-    _G_int32_t seed2 = initialSeedTwo;
+    int32_t seed1 = initialSeedOne;
+    int32_t seed2 = initialSeedTwo;
 
     //
     //	Most people pick stupid seed numbers that do not have enough
@@ -79,9 +79,9 @@ MLCG::reset()
     seedTwo = (seedTwo % 2147483397) + 1;
 }
 
-_G_uint32_t MLCG::asLong()
+uint32_t MLCG::asLong()
 {
-    _G_int32_t k = seedOne % 53668;
+    int32_t k = seedOne % 53668;
 
     seedOne = 40014 * (seedOne-k * 53668) - k * 12211;
     if (seedOne < 0) {
@@ -94,7 +94,7 @@ _G_uint32_t MLCG::asLong()
 	seedTwo += 2147483399;
     }
 
-    _G_int32_t z = seedOne - seedTwo;
+    int32_t z = seedOne - seedTwo;
     if (z < 1) {
 	z += 2147483562;
     }
