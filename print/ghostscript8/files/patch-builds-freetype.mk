--- builds/freetype.mk.orig	2008-03-07 19:25:58.000000000 +0900
+++ builds/freetype.mk	2008-03-07 19:15:21.000000000 +0900
@@ -152,7 +152,7 @@
              $(CFLAGS) \
              $DFT2_BUILD_LIBRARY \
              $DFT_CONFIG_MODULES_H="<ftmodule.h>" \
-             $(FTOPTION_FLAG)
+             $(FTOPTION_FLAG) -fPIC
 FT_CC      = $(CC) $(FT_CFLAGS)
 FT_COMPILE = $(CC) $(ANSIFLAGS) $(FT_CFLAGS)
 
