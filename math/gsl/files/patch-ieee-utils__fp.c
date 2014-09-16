--- ieee-utils/fp.c.orig	2014-09-16 17:19:39 UTC
+++ ieee-utils/fp.c
@@ -22,6 +22,8 @@
 #include "fp-aix.c"
 #elif HAVE_TRU64_IEEE_INTERFACE
 #include "fp-tru64.c"
+#elif HAVE_DECL_FEENABLEEXCEPT || HAVE_DECL_FESETTRAPENABLE
+#include "fp-gnuc99.c"
 #elif HAVE_FREEBSD_IEEE_INTERFACE
 #include "fp-freebsd.c"
 #elif HAVE_OS2EMX_IEEE_INTERFACE
@@ -43,8 +45,6 @@
 # else
 #  include "fp-darwin86.c"
 #endif
-#elif HAVE_DECL_FEENABLEEXCEPT || HAVE_DECL_FESETTRAPENABLE
-#include "fp-gnuc99.c"
 #else
 #include "fp-unknown.c" 
 #endif
