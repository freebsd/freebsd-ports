--- src/preferences.cc.orig	2007-01-22 23:36:04.000000000 +0100
+++ src/preferences.cc	2008-04-08 17:00:17.000000000 +0200
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
