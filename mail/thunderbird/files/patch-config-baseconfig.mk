--- mozilla/config/baseconfig.mk~
+++ mozilla/config/baseconfig.mk
@@ -1,7 +1,7 @@
-includedir := $(includedir)/$(MOZ_APP_NAME)-$(MOZ_APP_VERSION)
-idldir = $(datadir)/idl/$(MOZ_APP_NAME)-$(MOZ_APP_VERSION)
-installdir = $(libdir)/$(MOZ_APP_NAME)-$(MOZ_APP_VERSION)
-sdkdir = $(libdir)/$(MOZ_APP_NAME)-devel-$(MOZ_APP_VERSION)
+includedir := $(includedir)/%%MOZILLA%%
+idldir = $(datadir)/idl/%%MOZILLA%%
+installdir = $(libdir)/%%MOZILLA%%
+sdkdir = $(libdir)/%%MOZILLA%%
 ifndef TOP_DIST
 TOP_DIST = dist
 endif
