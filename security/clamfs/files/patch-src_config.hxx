--- src/config.hxx.orig	2009-11-29 19:19:33 UTC
+++ src/config.hxx
@@ -30,7 +30,7 @@
 #include "config.h"
 
 #include <map>
-#include <tr1/unordered_map>
+#include <unordered_map>
 #include <cc++/xml.h>
 
 #ifdef DMALLOC
@@ -45,11 +45,6 @@ namespace clamfs {
    \brief STanDard namespace
 */
 using namespace std;
-
-/*!\namespace tr1
-   \brief ISO/IEC TR 19768 namespace
-*/
-using namespace tr1;
 
 /*!\namespace ost
    \brief GNU CommonC++ namespace
