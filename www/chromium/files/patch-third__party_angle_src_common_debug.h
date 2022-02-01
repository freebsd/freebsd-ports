--- third_party/angle/src/common/debug.h.orig	2021-12-31 01:00:47 UTC
+++ third_party/angle/src/common/debug.h
@@ -399,7 +399,7 @@ std::ostream &FmtHex(std::ostream &os, T value)
 #    define ANGLE_DISABLE_STRUCT_PADDING_WARNINGS
 #endif
 
-#if defined(__clang__)
+#if defined(__clang__) && !defined(__FreeBSD__)
 #    define ANGLE_DISABLE_SUGGEST_OVERRIDE_WARNINGS                               \
         _Pragma("clang diagnostic push")                                          \
             _Pragma("clang diagnostic ignored \"-Wsuggest-destructor-override\"") \
