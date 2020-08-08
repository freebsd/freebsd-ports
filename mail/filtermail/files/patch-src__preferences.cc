--- src/preferences.cc.orig	2014-05-17 17:19:41 UTC
+++ src/preferences.cc
@@ -24,6 +24,7 @@
 #include <vector>
 #include <stdexcept>
 #include <cstdio>
+#include <wordexp.h>
 #include "preferences.hh"
 #include "filter.hh"
 #include "filtermail.hh"
@@ -34,7 +35,7 @@
 
 extern "C"
 {
-#include <wordexp.h>
+#include <glob.h>
 #include <sys/types.h>
 #include <regex.h>
 }
