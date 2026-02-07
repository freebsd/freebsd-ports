Index: src/ppp.h
===================================================================
--- src/ppp.h	(revision 2411)
+++ src/ppp.h	(working copy)
@@ -69,20 +69,15 @@
   #define assert(e)	((e) ? (void)0 : DoAssert(__FILE__, __LINE__, #e))
 
 #ifdef __clang__
-
+#ifndef NO_THREAD_SAFETY_ANALYSIS
 #ifndef THREAD_ANNOTATION_ATTRIBUTE__
   #define THREAD_ANNOTATION_ATTRIBUTE__(x)   __attribute__((x))
-#else
-  #define THREAD_ANNOTATION_ATTRIBUTE__(x)
 #endif
-
-#ifndef NO_THREAD_SAFETY_ANALYSIS
   #define NO_THREAD_SAFETY_ANALYSIS \
 	THREAD_ANNOTATION_ATTRIBUTE__(no_thread_safety_analysis)
+#endif
 #else
   #define NO_THREAD_SAFETY_ANALYSIS
-#endif
-
 #endif /* __clang__ */
 
   /* Giant Mutex handling */
