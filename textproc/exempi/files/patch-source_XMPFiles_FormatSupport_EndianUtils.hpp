--- source/XMPFiles/FormatSupport/EndianUtils.hpp.orig	2008-07-08 15:22:01.000000000 -0500
+++ source/XMPFiles/FormatSupport/EndianUtils.hpp	2008-07-08 15:22:35.000000000 -0500
@@ -57,7 +57,7 @@
 #    define kBigEndianHost 1
 #  endif
 # else
-#  include <endian.h>
+#  include <machine/endian.h>
 #  if BYTE_ORDER == BIG_ENDIAN
 #   define kBigEndianHost 1
 #  elif BYTE_ORDER == LITTLE_ENDIAN
