--- src/rpsl/rpsl/object.cc.orig	2004-07-30 12:58:14.000000000 +0200
+++ src/rpsl/rpsl/object.cc
@@ -52,7 +52,11 @@
 //  Author(s): Cengiz Alaettinoglu <cengiz@ISI.EDU>
 
 #include "config.h"
+#if (__GNUC__ > 2)
 #include <istream>
+#else
+#include <istream.h>
+#endif
 #include <cstdio>
 #include <sstream>
 #include <fstream>
