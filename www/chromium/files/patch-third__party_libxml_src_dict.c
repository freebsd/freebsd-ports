--- third_party/libxml/src/dict.c.orig	2022-02-07 13:39:41 UTC
+++ third_party/libxml/src/dict.c
@@ -38,8 +38,8 @@
  *  list we will use the BigKey algo as soon as the hash size grows
  *  over MIN_DICT_SIZE so this actually works
  */
-#if defined(HAVE_RAND) && defined(HAVE_SRAND) && defined(HAVE_TIME) && \
-    !defined(FUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION)
+#if (defined(HAVE_RAND) && defined(HAVE_SRAND) && defined(HAVE_TIME) && \
+    !defined(FUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION)) || defined(HAVE_ARC4RANDOM)
 #define DICT_RANDOMIZATION
 #endif
 
@@ -140,7 +140,7 @@ static xmlRMutexPtr xmlDictMutex = NULL;
 static int xmlDictInitialized = 0;
 
 #ifdef DICT_RANDOMIZATION
-#ifdef HAVE_RAND_R
+#if defined(HAVE_RAND_R) && !defined(HAVE_ARC4RANDOM)
 /*
  * Internal data for random function, protected by xmlDictMutex
  */
@@ -181,7 +181,7 @@ int __xmlInitializeDict(void) {
         return(0);
     xmlRMutexLock(xmlDictMutex);
 
-#ifdef DICT_RANDOMIZATION
+#if defined(DICT_RANDOMIZATION) && !defined(HAVE_ARC4RANDOM)
 #ifdef HAVE_RAND_R
     rand_seed = time(NULL);
     rand_r(& rand_seed);
@@ -201,13 +201,17 @@ int __xmlRandom(void) {
     if (xmlDictInitialized == 0)
         __xmlInitializeDict();
 
+#ifdef HAVE_ARC4RANDOM
+    ret = arc4random();
+#else
     xmlRMutexLock(xmlDictMutex);
-#ifdef HAVE_RAND_R
+#  ifdef HAVE_RAND_R
     ret = rand_r(& rand_seed);
-#else
+#  else
     ret = rand();
-#endif
+#  endif
     xmlRMutexUnlock(xmlDictMutex);
+#endif
     return(ret);
 }
 #endif
