diff -cr ../Sablot-0.44/Sablot/engine/parser.h Sablot/engine/parser.h
*** ../Sablot-0.44/Sablot/engine/parser.h	Thu Sep 14 15:09:03 2000
--- Sablot/engine/parser.h	Sun Nov 12 17:07:31 2000
***************
*** 39,51 ****
  #include "base.h"
  #include "output.h"
  
! #if defined (HAVE_XMLPARSE_H) || defined (HAVE_EXPAT_SRC)
! #include <xmlparse.h>
! #elif defined (HAVE_XMLTOK_XMLPARSE_H)
! #include <xmltok/xmlparse.h>
! #elif defined (WIN32)
! #include "xmlparse.h"
! #endif
  
  class Tree;
  class DataLine;
--- 39,45 ----
  #include "base.h"
  #include "output.h"
  
! #include <expat.h>
  
  class Tree;
  class DataLine;
