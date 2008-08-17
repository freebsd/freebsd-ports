--- Makefile.PL.orig	2008-08-16 14:57:00.000000000 +0200
+++ Makefile.PL	2008-08-16 15:03:45.000000000 +0200
@@ -67,9 +67,12 @@ extra_install:
 	done
 	
 	install -d $(DESTDIR)$(PREFIX)/lib/ikiwiki/plugins
-	for file in `find plugins -maxdepth 1 -type f ! -wholename plugins/.\* | grep -v demo`; do \
-		cp -a $$file $(DESTDIR)$(PREFIX)/lib/ikiwiki/plugins; \
-	done \
+	for file in `find plugins -maxdepth 1 -type f ! -wholename plugins/.\* ! -name \*demo\* -name \*.py`; do \
+		install -m 644 $$file $(DESTDIR)$(PREFIX)/lib/ikiwiki/plugins; \
+	done
+	for file in `find plugins -maxdepth 1 -type f ! -wholename plugins/.\* ! -name \*demo\* ! -name \*.py`; do \
+		install -m 755 $$file $(DESTDIR)$(PREFIX)/lib/ikiwiki/plugins; \
+	done
 
 	install -d $(DESTDIR)$(PREFIX)/share/man/man1
 	install -m 644 ikiwiki.man $(DESTDIR)$(PREFIX)/share/man/man1/ikiwiki.1
