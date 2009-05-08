--- qfaktury.pro.orig  2009-04-20 10:16:58.000000000 +0200
+++ qfaktury.pro       2009-04-20 10:20:27.000000000 +0200
@@ -66,15 +66,15 @@
 TRANSLATIONS += qfaktury_de.ts \
     qfaktury_en.ts \
     qfaktury_pl.ts
-pixmaps.path = /usr/local/share/qfaktury/icons
+pixmaps.path = @PREFIX@/share/qfaktury/icons
 pixmaps.files = icons/*.png
-css.path = /usr/local/share/qfaktury/templates
+css.path = @PREFIX@/share/qfaktury/templates
 css.files = templates/*.css
-languages.path = /usr/local/share/qfaktury
+languages.path = @PREFIX@/share/qfaktury
 languages.files = *.qm
-desktop.path = /usr/local/share/applications
+desktop.path = @PREFIX@/share/applications
 desktop.files = *.desktop
-target.path = /usr/local/bin
+target.path = @PREFIX@/bin
 INSTALLS += target \
     pixmaps \
     css \
