Fix fallout from http://hg.mozilla.org/releases/comm-release/rev/a6ab55f00e21
XPIDL_LINK being undefined breaks enigmail build
--- config/config.mk.orig	Tue Dec 10 10:22:36 2013
+++ config/config.mk	Tue Dec 10 10:22:57 2013
@@ -325,6 +325,7 @@ MY_RULES	:= $(DEPTH)/config/myrules.mk
 # Default command macros; can be overridden in <arch>.mk.
 #
 CCC		= $(CXX)
+XPIDL_LINK = $(PYTHON) $(LIBXUL_DIST)/sdk/bin/xpt.py link
 
 OS_INCLUDES += $(NSPR_CFLAGS) $(NSS_CFLAGS) $(MOZ_JPEG_CFLAGS) $(MOZ_PNG_CFLAGS) $(MOZ_ZLIB_CFLAGS)
 

