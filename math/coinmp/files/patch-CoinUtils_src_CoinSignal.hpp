--- CoinUtils/src/CoinSignal.hpp.orig	2015-04-15 15:07:42 UTC
+++ CoinUtils/src/CoinSignal.hpp
@@ -44,7 +44,7 @@
 //-----------------------------------------------------------------------------
 
 #if defined(__FreeBSD__) && defined(__GNUC__)
-   typedef __decltype(SIG_DFL) CoinSighandler_t;
+   typedef typeof(SIG_DFL) CoinSighandler_t;
 #  define CoinSighandler_t_defined
 #endif
 
