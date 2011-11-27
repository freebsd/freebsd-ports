--- bridge/bridge.mk.orig	2011-11-24 18:31:11.000000000 +0100
+++ bridge/bridge.mk	2011-11-24 18:31:23.000000000 +0100
@@ -38,10 +38,10 @@
 
 APP_LIBXUL_DIRS += $(DEPTH)$(SUBDIR)/mozilla/xpfe/components/autocomplete
 
-#ifdef MOZ_LDAP_XPCOM
+ifdef MOZ_LDAP_XPCOM
 APP_LIBXUL_STATICDIRS += $(DEPTH)$(SUBDIR)/ldap/sdks/c-sdk
 APP_LIBXUL_DIRS += $(DEPTH)$(SUBDIR)/ldap/xpcom
-#endif
+endif
 
 #ifdef MOZ_MORK
 APP_LIBXUL_DIRS += $(DEPTH)$(SUBDIR)/db/mork
