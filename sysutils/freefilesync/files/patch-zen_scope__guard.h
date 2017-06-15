--- ../../zen/scope_guard.h.orig	2016-03-31 20:08:04 UTC
+++ ../../zen/scope_guard.h
@@ -14,7 +14,7 @@
 //best of Zen, Loki and C++17
 
 
-#ifdef ZEN_WIN
+#if defined(ZEN_WIN) || (defined(_LIBCPP_VERSION) && _LIBCPP_VERSION >= 3700)
 inline int getUncaughtExceptionCount() { return std::uncaught_exceptions(); }
 
 #elif defined ZEN_LINUX || defined ZEN_MAC
