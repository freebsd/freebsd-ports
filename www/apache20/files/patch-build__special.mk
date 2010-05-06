--- ./build/special.mk.orig	2006-07-12 03:40:55.000000000 -0400
+++ ./build/special.mk	2010-05-06 16:06:03.734831750 -0400
@@ -26,7 +26,7 @@
 install-modules:
 	@test -d $(DESTDIR)$(libexecdir) || $(MKINSTALLDIRS) $(DESTDIR)$(libexecdir);
 	@builtin='$(BUILTIN_LIBS)'; \
-	has_mod_so=`echo $$builtin|sed 's/^.*mod_so.*$$/has_mod_so/'`; \
+	has_mod_so=`echo $$builtin|sed 's/^.*libmod_so.*$$/has_mod_so/'`; \
 	if [ "x$$has_mod_so" = "xhas_mod_so" ]; then \
 		list='$(shared)'; \
 		for i in $$list; do \
