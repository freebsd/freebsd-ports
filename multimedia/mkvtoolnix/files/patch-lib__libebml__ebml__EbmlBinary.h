--- ./lib/libebml/ebml/EbmlBinary.h.orig	2013-09-16 22:01:58.000000000 +0200
+++ ./lib/libebml/ebml/EbmlBinary.h	2013-10-09 08:13:47.119105934 +0200
@@ -41,6 +41,7 @@
 
 #include "EbmlTypes.h"
 #include "EbmlElement.h"
+#include <stdlib.h>
 
 // ----- Added 10/15/2003 by jcsston from Zen -----
 #if defined (__BORLANDC__) //Maybe other compilers?
