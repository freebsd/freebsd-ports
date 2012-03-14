--- bridge/bridge.mk.orig	2012-03-13 06:23:10.000000000 +0100
+++ bridge/bridge.mk	2012-03-14 12:28:03.000000000 +0100
@@ -38,17 +38,19 @@
 
 APP_LIBXUL_DIRS += $(DEPTH)$(SUBDIR)/mozilla/xpfe/components/autocomplete
 
-#ifdef MOZ_LDAP_XPCOM
+ifdef MOZ_LDAP_XPCOM
 APP_LIBXUL_STATICDIRS += $(DEPTH)$(SUBDIR)/ldap/sdks/c-sdk
 APP_LIBXUL_DIRS += $(DEPTH)$(SUBDIR)/ldap/xpcom
-#endif
+endif
 
 #ifdef MOZ_MORK
 APP_LIBXUL_DIRS += $(DEPTH)$(SUBDIR)/db/mork
 #endif
 
+ifdef disabled
 APP_LIBXUL_DIRS += \
   $(DEPTH)$(SUBDIR)/mailnews/base \
   $(DEPTH)$(SUBDIR)/mailnews/mime/public \
   $(DEPTH)$(SUBDIR)/mailnews \
   $(NULL)
+endif
