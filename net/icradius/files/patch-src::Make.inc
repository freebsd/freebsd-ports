--- src/Make.inc.orig	Wed Jun  6 23:21:33 2001
+++ src/Make.inc	Tue Jun 26 12:43:50 2001
@@ -4,7 +4,7 @@
 #
 #
 
-RADIUS_DIR = /etc/raddb
+RADIUS_DIR = ${PREFIX}/etc/raddb
 
 SERVER_OBJS    = radiusd.o dict.o files.o filters.o util.o md5.o attrprint.o \
 			acct.o radius.o pam.o log.o version.o proxy.o \
@@ -92,8 +92,8 @@
 	install -d $(SBINDIR)
 	install -d $(BINDIR)
 	install -d $(RADIUS_DIR)
-	install -m 755 -s radiusd $(SBINDIR)/radiusd
-	install -m 755    checkrad.pl $(SBINDIR)/checkrad
+	install -c -m 755 -s radiusd $(SBINDIR)/radiusd
+	install -c -m 755    checkrad.pl $(SBINDIR)/checkrad
 	# Install the config files
 	@echo "Creating/updating files in $(RADIUS_DIR)"; \
 	cd ../raddb; \
