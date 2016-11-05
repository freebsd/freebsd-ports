PR ports/187433: fix build on FreeBSD 10 
========================================

--- src/LogCache.cc.orig	2016-10-20 15:07:59 UTC
+++ src/LogCache.cc
@@ -24,6 +24,7 @@
 
 #include "LogCache.h"
 #include <dirent.h>
+#include <pthread.h>
 #include <stdarg.h>
 #include <stddef.h>
 #include <stdio.h>
