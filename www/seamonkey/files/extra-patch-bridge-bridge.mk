--- bridge/bridge.mk.orig	2011-10-24 10:44:24.000000000 +0200
+++ bridge/bridge.mk	2011-10-24 10:44:56.000000000 +0200
@@ -38,10 +38,10 @@
 
 APP_LIBXUL_DIRS += $(DEPTH)$(SUBDIR)/mozilla/xpfe/components/autocomplete
 
-#ifdef MOZ_LDAP_XPCOM
+ifdef MOZ_LDAP_XPCOM
 APP_LIBXUL_STATICDIRS += $(DEPTH)$(SUBDIR)/ldap/sdks/c-sdk
 APP_LIBXUL_DIRS += $(DEPTH)$(SUBDIR)/ldap/xpcom
-#endif
+endif
 
 ifdef MOZ_MAIL_NEWS
 APP_LIBXUL_DIRS += \
