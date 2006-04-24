--- rules.make.orig	Sat Apr 15 06:19:19 2006
+++ rules.make	Sat Apr 15 06:20:57 2006
@@ -12,7 +12,8 @@
 		cat=`basename $$cat`; \
 		lang=`echo $$cat | sed 's/\.mo$$//'`; \
 		dir=$(DESTDIR)$(localedir)/$$lang/LC_MESSAGES; \
-		$(INSTALL_DATA) -D $$cat $$dir/$(DOMAIN).mo; \
+		mkdir -p $$dir; \
+		$(INSTALL_DATA) $$cat $$dir/$(DOMAIN).mo; \
 	done
 
 uninstall-hook:
