--- searchall_cb.cc.orig	Sun May  4 17:21:26 1997
+++ searchall_cb.cc	Thu Jun 14 18:01:36 2007
@@ -4,6 +4,8 @@
 
 #include <Xm/List.h>
 #include <X11/cursorfont.h>
+#include <assert.h>
+#include <inttypes.h>
 #include <stdio.h>
 #include "globals.h"
 
@@ -26,7 +28,10 @@
   gefunden   = new unsigned long[b.last+1];
   gefunden[0]= 0;
   ref        = new char[100];
-  cis=(short)client_data;
+
+  /* We're about to convert void * to short: fasten some seatbelts. */
+  assert(((intptr_t)client_data >> 16) == 0);
+  cis=(short)((intptr_t)client_data & 0xFFFF);
 
   switch((int)b.d->id) {
   case 1:  // .... and;
