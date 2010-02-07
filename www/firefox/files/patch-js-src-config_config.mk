--- js/src/config/config.mk.orig	2009-08-07 00:49:23.000000000 +0200
+++ js/src/config/config.mk	2009-08-09 20:50:05.000000000 +0200
@@ -506,6 +506,7 @@
   -I$(srcdir) \
   -I. \
   -I$(DIST)/include -I$(DIST)/include/nsprpub \
+  -I%%LOCALBASE%%/include \
   $(if $(LIBXUL_SDK),-I$(LIBXUL_SDK)/include -I$(LIBXUL_SDK)/include/nsprpub) \
   $(OS_INCLUDES) \
   $(NULL) 
