--- eplugin.mk.orig	Wed Aug 31 17:21:09 2005
+++ eplugin.mk	Wed Aug 31 17:22:10 2005
@@ -0,0 +1,2 @@
+%.eplug: %.eplug.in
+	sed -e 's|\@PLUGINDIR\@|$(eplugindir)|;s|\@LOCALEDIR\@|$(localedir)|;s|\@GETTEXT_PACKAGE\@|$(GETTEXT_PACKAGE)|' $< > $@
