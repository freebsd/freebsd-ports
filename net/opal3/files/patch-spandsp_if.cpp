--- plugins/fax/fax_spandsp/spandsp_util/spandsp_if.cpp.orig	2011-12-26 21:04:48.000000000 +0000
+++ plugins/fax/fax_spandsp/spandsp_util/spandsp_if.cpp	2011-12-26 21:05:21.000000000 +0000
@@ -23,6 +23,7 @@
  * $Id: spandsp_if.cpp,v 1.7 2007/07/24 04:39:44 csoutheren Exp $
  */
 
+#define __STDC_LIMIT_MACROS
 #include "spandsp_if.h"
 
 #include <iostream>
