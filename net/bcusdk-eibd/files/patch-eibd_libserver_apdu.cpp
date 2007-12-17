--- eibd/libserver/apdu.cpp.orig	2007-11-08 15:31:33.000000000 +0000
+++ eibd/libserver/apdu.cpp	2007-12-08 15:08:18.000000000 +0000
@@ -18,8 +18,7 @@
 */
 
 #include <stdio.h>
-#include <string.h>
 #include "apdu.h"
 
 APDU *
 APDU::fromPacket (const CArray & c)
