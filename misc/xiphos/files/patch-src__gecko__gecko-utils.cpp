--- ./src/gecko/gecko-utils.cpp.orig	2009-08-09 18:52:26.000000000 -0400
+++ ./src/gecko/gecko-utils.cpp	2009-09-28 13:36:48.000000000 -0400
@@ -38,10 +38,6 @@
 # undef NS_EXPORT_
 #endif
 
-#ifdef HAVE_GECKO_1_9
-#include <gtkmozembed_glue.cpp>
-#endif
-
 #include <gtkmozembed.h>
 #include <gtkmozembed_internal.h>
 #include <nsCOMPtr.h>
