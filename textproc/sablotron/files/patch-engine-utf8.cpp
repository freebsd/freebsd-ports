diff -crN Sablot-0.51.orig/Sablot/engine/utf8.cpp Sablot-0.51/Sablot/engine/utf8.cpp
*** Sablot/engine/utf8.cpp	Fri Feb 23 15:03:03 2001
--- Sablot/engine/utf8.cpp	Fri Feb 23 15:02:23 2001
***************
*** 55,61 ****
--- 55,63 ----
  #include "utf8.h"
  
  #ifdef HAVE_ICONV_H
+ extern "C" {
  #include <iconv.h>
+ }
  #endif
  
  #if defined(HAVE_WCHAR_H) || defined(_MSC_VER)
