--- src/normalform/SetOfSymbol.cc.orig	2004-07-30 12:58:13.000000000 +0200
+++ src/normalform/SetOfSymbol.cc
@@ -51,7 +51,11 @@
 //
 //  Author(s): Cengiz Alaettinoglu <cengiz@ISI.EDU>
 
+#if (__GNUC__ > 2)
 #include <ostream>
+#else
+#include <ostream.h>
+#endif
 #include <cstdio>
 #include <cassert>
 #include "config.h"
