--- ./lib/libsidplay2/libsidplay/src/mos6510/mos6510.h.orig	2012-01-02 11:44:06.000000000 +0100
+++ ./lib/libsidplay2/libsidplay/src/mos6510/mos6510.h	2012-01-02 11:44:18.000000000 +0100
@@ -36,7 +36,7 @@
 #include "config.h"
 #include "component.h"
 #include "sidenv.h"
-#include "event.h"
+#include "sidplay/event.h"
 
 #undef  MOS6510_VERSION
 #undef  MOS6510_DATE
