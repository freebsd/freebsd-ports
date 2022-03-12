FXRex.cpp:4676:10: fatal error: 'fxrexdbg.h' file not found

This line was commented out in 1.7.78 and uncommented in 1.7.79, but the file
fxrexdbg.h does not exist anywhere in the distribution.

--- lib/FXRex.cpp.orig	2022-03-12 18:13:56 UTC
+++ lib/FXRex.cpp
@@ -503,7 +503,7 @@
 */
 
 #define TOPIC_CONSTRUCT 1000
-#define TOPIC_REXDUMP   1014          // Debugging regex code
+//#define TOPIC_REXDUMP   1014          // Debugging regex code
 
 
 // As close to infinity as we're going to get; this seems big enough.  We can not make
