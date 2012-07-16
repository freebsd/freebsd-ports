--- polybori-0.8.1.p2/patches/Cudd.cudd.cudd.h.patch.orig	2012-04-13 01:19:43.000000000 +0000
+++ polybori-0.8.1.p2/patches/Cudd.cudd.cudd.h.patch	2012-04-13 01:22:34.000000000 +0000
@@ -0,0 +1,15 @@
+--- a/Cudd/cudd/cudd.h.orig	2012-03-15 22:47:56.000000000 +0000
++++ b/Cudd/cudd/cudd.h	2012-04-13 01:21:09.000000000 +0000
+@@ -87,6 +87,12 @@
+ #endif
+ 
+ #ifdef __cplusplus
++#include <cstdio>
++#else
++#include <stdio.h>
++#endif
++
++#ifdef __cplusplus
+ extern "C" {
+ #endif
+ 
