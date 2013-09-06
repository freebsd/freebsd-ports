--- ./ebml/EbmlBinary.h.orig	2013-03-19 19:42:58.000000000 +0100
+++ ./ebml/EbmlBinary.h	2013-09-06 22:17:55.987709299 +0200
@@ -41,6 +41,7 @@
 
 #include "EbmlTypes.h"
 #include "EbmlElement.h"
+#include <stdlib.h>
 
 // ----- Added 10/15/2003 by jcsston from Zen -----
 #if defined (__BORLANDC__) //Maybe other compilers?
