--- Makefile.PL.orig	Sun Apr 29 12:57:51 2007
+++ Makefile.PL	Sun Apr 29 13:27:51 2007
@@ -47,8 +47,12 @@ extra_clean:
 
 extra_install:
 	install -d $(DESTDIR)$(PREFIX)/share/ikiwiki
-	find basewiki templates \( -type f -or -type l \) ! -regex '.*\.svn.*' \
-		-exec cp --parents -aL {} $(DESTDIR)$(PREFIX)/share/ikiwiki \;
+	for dir in `find -L basewiki templates -type d ! -regex '.*\.svn.*'`; do \
+		install -d $(DESTDIR)$(PREFIX)/share/ikiwiki/$$dir; \
+		for file in `find -L $$dir -maxdepth 1 -type f`; do \
+			install -m 644 $$file $(DESTDIR)$(PREFIX)/share/ikiwiki/$$dir; \
+		done; \
+	done
 
 	install -d $(DESTDIR)$(PREFIX)/share/man/man1
 	install -m 644 ikiwiki.man $(DESTDIR)$(PREFIX)/share/man/man1/ikiwiki.1
