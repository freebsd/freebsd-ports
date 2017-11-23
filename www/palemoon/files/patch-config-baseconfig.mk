--- config/baseconfig.mk.orig	2017-11-14 14:36:13 UTC
+++ config/baseconfig.mk
@@ -2,10 +2,10 @@
 # directly in python/mozbuild/mozbuild/base.py for gmake validation.
 # We thus use INCLUDED_AUTOCONF_MK to enable/disable some parts depending
 # whether a normal build is happening or whether the check is running.
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
