Add missing include that was removed in 1.7.85 for some reason. FXSelector
is defined in FXMetaClass.h. Fox itself builds, but audio/gogglesmm fails.

/usr/local/include/fox-1.7/FXObject.h:135:3: fatal error: no type named 'FXSelector' in namespace 'FX'
  135 |   FXDECLARE(FXObject)
      |   ^~~~~~~~~~~~~~~~~~~
/usr/local/include/fox-1.7/FXObject.h:50:28: note: expanded from macro 'FXDECLARE'
   50 |    struct FXMapEntry { FX::FXSelector keylo; FX::FXSelector keyhi; long (classname::* func)(FX::FXObject*,FX::FXSelector,void*); }; \
      |                        ~~~~^

Upstream has been notified of this issue:
https://sourceforge.net/p/foxgui/mailman/foxgui-users/thread/CAJE75NFrWfZUx%3DifHt2GrzbwPrRSG9DaHLP3Xa%2Bo2DCZwPFTTw%40mail.gmail.com/#msg58809602

--- include/FXObject.h.orig	2024-06-30 15:47:37 UTC
+++ include/FXObject.h
@@ -25,6 +25,10 @@
 #include "FXCallback.h"
 #endif
 
+#ifndef FXMETACLASS_H
+#include "FXMetaClass.h"
+#endif
+
 namespace FX {
 
 
