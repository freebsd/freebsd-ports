--- sparsersb.cc.orig	2018-06-23 19:12:49 UTC
+++ sparsersb.cc
@@ -97,7 +97,7 @@
 #define RSBOI_WARN( MSG )
 #endif
 #define RSBOI_TODO( MSG ) RSBOI_WARN( MSG )/* new */
-#define RSBOI_FIXME( MSG ) RSBOI_WARN( "FIXME: "MSG )/* new */
+#define RSBOI_FIXME( MSG ) RSBOI_WARN( "FIXME: " MSG )/* new */
 
 #define RSBOI_PRINTF( ... ) printf( __VA_ARGS__ )
 #if RSBOI_VERBOSE
