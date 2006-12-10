--- src/rpsl/rpsl/rpsl_filter.cc.orig	2004-07-30 12:58:15.000000000 +0200
+++ src/rpsl/rpsl/rpsl_filter.cc
@@ -52,7 +52,11 @@
 //  Author(s): Cengiz Alaettinoglu <cengiz@ISI.EDU>
 
 #include "config.h"
+#if (__GNUC__ > 2)
 #include <ostream>
+#else
+#include <ostream.h>
+#endif
 #include <cstdio>
 #include "rpsl_filter.hh"
 #include "rpsl_attr.hh"
