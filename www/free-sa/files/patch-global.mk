--- global.mk.orig	Wed Apr  4 15:43:18 2007
+++ global.mk	Wed Apr  4 15:43:35 2007
@@ -10,7 +10,7 @@
 # etc dir
 ETCDIR = $(PREFIX)/etc/$(PROGLNAME)
 # where put reports (you can change it later via free-sa.conf configuration file)
-WWWDIR = $(PREFIX)/var/www/htdocs/$(PROGLNAME)
+WWWDIR = $(PREFIX)/www/data/$(PROGLNAME)
 # dir for temporary data storing (you can change it later via free-sa.conf configuration file)
 TMPDIR = /var/cache/$(PROGLNAME)
 # where log file lives (you can change it later via free-sa.conf configuration file)
