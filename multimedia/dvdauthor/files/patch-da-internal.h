--- src/da-internal.h.orig	Tue Dec  9 22:43:52 2003
+++ src/da-internal.h	Wed Dec 17 00:28:03 2003
@@ -20,6 +20,8 @@
 #ifndef __DA_INTERNAL_H_
 #define __DA_INTERNAL_H_
 
+#include <sys/types.h>
+
 enum {VM_NONE=0,VM_MPEG1=1,VM_MPEG2=2};
 enum {VS_NONE=0,VS_720H=1,VS_704H=2,VS_352H=3,VS_352L=4};
 enum {VF_NONE=0,VF_NTSC=1,VF_PAL=2};
