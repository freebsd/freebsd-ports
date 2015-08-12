--- lib/libebml/ebml/EbmlBinary.h.orig	2015-07-18 11:39:43 UTC
+++ lib/libebml/ebml/EbmlBinary.h
@@ -41,6 +41,7 @@
 
 #include "EbmlTypes.h"
 #include "EbmlElement.h"
+#include <stdlib.h>
 
 // ----- Added 10/15/2003 by jcsston from Zen -----
 #if defined (__BORLANDC__) //Maybe other compilers?
