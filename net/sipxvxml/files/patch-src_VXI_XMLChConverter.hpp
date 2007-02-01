--- ./src/VXI/XMLChConverter.hpp.orig	Fri Dec 29 11:01:48 2006
+++ ./src/VXI/XMLChConverter.hpp	Fri Dec 29 11:02:27 2006
@@ -27,7 +27,7 @@
 // provides an imperfect conversion from UTF-16 to UTF-32, ignoring all
 // surrogate pairs.
 
-#if defined(__linux__) || \
+#if defined(__linux__) || defined(__FreeBSD__) || \
     defined(SOLARIS) || defined(__SVR4) || defined(UNIXWARE)
 #define UTF16TO32
 
