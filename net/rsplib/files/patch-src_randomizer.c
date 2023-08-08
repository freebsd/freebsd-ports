--- src/randomizer.c.orig	2021-02-17 14:14:20 UTC
+++ src/randomizer.c
@@ -32,13 +32,12 @@
 #include <math.h>
 #include <stdlib.h>
 
-
+/*
 #ifdef NDEBUG
 #undef min
 #undef max
 #include <omnetpp.h>
 #else
-/*
    It is tried to use /dev/urandom as random source first, since
    it provides high-quality random numbers. If /dev/urandom is not
    available, use the clib's random() function with a seed given
@@ -56,7 +55,6 @@
 
 static int   RandomSource = RS_TRY_DEVICE;
 static FILE* RandomDevice = NULL;
-#endif
 
 
 
@@ -84,11 +82,13 @@ uint64_t random64()
 /* ###### Get 32-bit random value ######################################## */
 uint32_t random32()
 {
+/*
 #ifdef NDEBUG
 #warning Using OMNeT++ random generator instead of time-seeded one!
    const double value = uniform(0.0, (double)0xffffffff);
    return((uint32_t)rint(value));
 #else
+*/
    uint32_t number;
 
    switch(RandomSource) {
@@ -116,7 +116,6 @@ uint32_t random32()
       break;
    }
    return(random());
-#endif
 }
 
 
