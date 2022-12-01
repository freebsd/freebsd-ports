--- third_party/libxml/src/dict.c.orig	2022-12-01 10:35:46 UTC
+++ third_party/libxml/src/dict.c
@@ -137,7 +137,7 @@ static xmlMutexPtr xmlDictMutex = NULL;
 static int xmlDictInitialized = 0;
 
 #ifdef DICT_RANDOMIZATION
-#ifdef HAVE_RAND_R
+#if defined(HAVE_RAND_R) && !defined(HAVE_ARC4RANDOM)
 /*
  * Internal data for random function, protected by xmlDictMutex
  */
@@ -180,7 +180,7 @@ int __xmlInitializeDict(void) {
         return(0);
     xmlMutexLock(xmlDictMutex);
 
-#ifdef DICT_RANDOMIZATION
+#if defined(DICT_RANDOMIZATION) && !defined(HAVE_ARC4RANDOM)
 #ifdef HAVE_RAND_R
     rand_seed = time(NULL);
     rand_r(& rand_seed);
@@ -200,13 +200,17 @@ int __xmlRandom(void) {
     if (xmlDictInitialized == 0)
         __xmlInitializeDict();
 
+#ifdef HAVE_ARC4RANDOM
+    ret = arc4random();
+#else
     xmlMutexLock(xmlDictMutex);
-#ifdef HAVE_RAND_R
+#  ifdef HAVE_RAND_R
     ret = rand_r(& rand_seed);
-#else
+#  else
     ret = rand();
-#endif
+#  endif
     xmlMutexUnlock(xmlDictMutex);
+#endif
     return(ret);
 }
 #endif
