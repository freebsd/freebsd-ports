diff -cr ../Sablot-0.44/Sablot/engine/utf8.cpp Sablot/engine/utf8.cpp
*** ../Sablot-0.44/Sablot/engine/utf8.cpp	Sun Nov 12 16:21:25 2000
--- Sablot/engine/utf8.cpp	Sun Nov 12 17:29:08 2000
***************
*** 38,44 ****
--- 38,46 ----
  #include "utf8.h"
  
  #ifdef HAVE_ICONV_H
+ extern "C" {
  #include <iconv.h>
+ }
  #endif
  
  /*  This MUST match the Encoding enum defined in utf8.h  */
