--- bridge/bridge.mk.orig	2011-09-29 01:10:49.000000000 +0200
+++ bridge/bridge.mk	2011-10-26 22:21:47.000000000 +0200
@@ -38,12 +38,12 @@
 
 APP_LIBXUL_DIRS += $(DEPTH)$(SUBDIR)/mozilla/xpfe/components/autocomplete
 
-#ifdef MOZ_LDAP_XPCOM
+ifdef MOZ_LDAP_XPCOM
 APP_LIBXUL_STATICDIRS += $(DEPTH)$(SUBDIR)/ldap/sdks/c-sdk
 APP_LIBXUL_DIRS += $(DEPTH)$(SUBDIR)/ldap/xpcom
-#endif
+endif
 
-ifdef MOZ_MAIL_NEWS
+ifdef disabled
 APP_LIBXUL_DIRS += \
   $(DEPTH)$(SUBDIR)/mailnews/base \
   $(DEPTH)$(SUBDIR)/mailnews/mime/public \
