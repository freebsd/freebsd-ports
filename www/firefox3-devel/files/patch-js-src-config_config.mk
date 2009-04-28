--- js/src/config/config.mk.orig	2009-04-28 11:14:01.760089946 +0000
+++ js/src/config/config.mk	2009-04-28 11:14:30.311093216 +0000
@@ -490,7 +490,7 @@
 INCLUDES	= $(LOCAL_INCLUDES) $(REQ_INCLUDES) $(REQ_INCLUDES_SDK) -I$(PUBLIC) $(OS_INCLUDES)
 
 ifndef MOZILLA_INTERNAL_API
-INCLUDES	+= -I$(LIBXUL_DIST)/sdk/include
+INCLUDES	+= -I$(LIBXUL_DIST)/sdk/include -I%%LOCALBASE%%/include
 endif
 
 include $(topsrcdir)/config/static-checking-config.mk
