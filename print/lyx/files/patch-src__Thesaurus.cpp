Build fix for gcc 4.5+, which complains about FILE not being defined in
mythes.hxx.
--- src/Thesaurus.cpp.orig	2012-12-25 17:28:52.000000000 +0200
+++ src/Thesaurus.cpp	2012-12-25 17:29:18.000000000 +0200
@@ -24,6 +24,7 @@
 #include "support/os.h"
 
 #ifdef USE_EXTERNAL_MYTHES
+#include <cstdio>
 #include MYTHES_H_LOCATION
 #else
 #include <cstdio>
