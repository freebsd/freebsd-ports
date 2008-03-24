--- source/XMPFiles/FormatSupport/EndianUtils.hpp.orig	2008-02-26 11:51:10.000000000 -0500
+++ source/XMPFiles/FormatSupport/EndianUtils.hpp	2008-02-26 11:51:17.000000000 -0500
@@ -38,7 +38,7 @@
 		#endif
 	#endif
 #elif XMP_UNIXBuild
-#include <endian.h>
+#include <machine/endian.h>
 	#if BYTE_ORDER == BIG_ENDIAN
 		#define kBigEndianHost 1
 	#elif BYTE_ORDER == LITTLE_ENDIAN
