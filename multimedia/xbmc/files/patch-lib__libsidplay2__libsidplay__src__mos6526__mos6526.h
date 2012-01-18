--- ./lib/libsidplay2/libsidplay/src/mos6526/mos6526.h.orig	2012-01-02 11:46:36.000000000 +0100
+++ ./lib/libsidplay2/libsidplay/src/mos6526/mos6526.h	2012-01-02 11:46:47.000000000 +0100
@@ -85,7 +85,7 @@
 #define _mos6526_h_
 
 #include "component.h"
-#include "event.h"
+#include "sidplay/event.h"
 
 class MOS6526: public component
 {
