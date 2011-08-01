--- mozilla/config/gcc-stl-wrapper.template.h.orig	2010-05-12 13:56:18.000000000 +0000
+++ mozilla/config/gcc-stl-wrapper.template.h	2010-05-12 13:56:52.000000000 +0000
@@ -89,7 +89,7 @@
 // -fshort-wchar).  We don't want that and so define our own inlined
 // __throw_*().
 #ifndef mozilla_throw_gcc_h
-#  include "mozilla/throw_gcc.h"
+#  include "../../memory/mozalloc/throw_gcc.h"
 #endif
 
 #endif  // if mozilla_${HEADER}_h
