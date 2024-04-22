--- Util/Compiler.hpp.orig	2024-02-12 08:08:33 UTC
+++ Util/Compiler.hpp
@@ -1,7 +1,7 @@
 #ifndef COMPILER_H_
 #define COMPILER_H_
 
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
 #include <features.h>
 // We need a GCC patch here due the following bug
 // <https://gcc.gnu.org/bugzilla/show_bug.cgi?id=107134>
