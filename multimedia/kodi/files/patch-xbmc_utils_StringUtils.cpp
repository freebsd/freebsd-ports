--- xbmc/utils/StringUtils.cpp.orig	2022-05-22 09:59:08 UTC
+++ xbmc/utils/StringUtils.cpp
@@ -17,7 +17,7 @@
 //------------------------------------------------------------------------
 
 #ifdef HAVE_NEW_CROSSGUID
-#include <crossguid/guid.hpp>
+#include <guid.hpp>
 #else
 #include <guid.h>
 #endif
