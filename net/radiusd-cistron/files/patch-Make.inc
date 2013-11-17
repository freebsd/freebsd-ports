--- src/Make.inc.orig	2003-04-10 12:51:47.000000000 +0200
+++ src/Make.inc	2013-11-17 09:08:44.000000000 +0100
@@ -4,7 +4,7 @@
 #
 #
 
-RADIUS_DIR    = /etc/raddb
+RADIUS_DIR    = ${PREFIX}/etc/raddb
 
 SERVER_OBJS   = radiusd.o files.o acct.o pam.o version.o proxy.o \
 			exec.o auth.o timestr.o cache.o readusers.o
@@ -115,36 +115,36 @@
 
 install:
 	# Install the binaries
-	$(DINSTALL) $(SBINDIR)
-	$(DINSTALL) $(BINDIR)
-	$(DINSTALL) $(RADIUS_DIR)
-	$(INSTALL) -m 755 -s radiusd  $(SBINDIR)/radiusd
-	$(INSTALL) -m 755 -s radrelay $(SBINDIR)/radrelay
-	$(INSTALL) -m 755 -s radwho  $(BINDIR)
-	$(INSTALL) -m 755 -s radzap  $(BINDIR)
-	$(INSTALL) -m 755 -s radclient $(BINDIR)
-	test -z "$(DBM)" || $(INSTALL) -m 755 -s builddbm $(BINDIR)
-	$(INSTALL) -m 755    checkrad.pl $(SBINDIR)/checkrad
-	$(INSTALL) -m 755    radlast $(BINDIR)
-	$(INSTALL) -m 755    radtest $(BINDIR)
+	$(DINSTALL) $(DESTROOT)$(SBINDIR)
+	$(DINSTALL) $(DESTROOT)$(BINDIR)
+	$(DINSTALL) $(DESTROOT)$(RADIUS_DIR)
+	$(INSTALL) -m 755 -s radiusd  $(DESTROOT)$(SBINDIR)/radiusd
+	$(INSTALL) -m 755 -s radrelay $(DESTROOT)$(SBINDIR)/radrelay
+	$(INSTALL) -m 755 -s radwho  $(DESTROOT)$(BINDIR)
+	$(INSTALL) -m 755 -s radzap  $(DESTROOT)$(BINDIR)
+	$(INSTALL) -m 755 -s radclient $(DESTROOT)$(BINDIR)
+	test -z "$(DBM)" || $(INSTALL) -m 755 -s builddbm $(DESTROOT)$(BINDIR)
+	$(INSTALL) -m 755    checkrad.pl $(DESTROOT)$(SBINDIR)/checkrad
+	$(INSTALL) -m 755    radlast $(DESTROOT)$(BINDIR)
+	$(INSTALL) -m 755    radtest $(DESTROOT)$(BINDIR)
 	# Install the man pages
 	@for section in 1 5 8; do \
 		$(DINSTALL) $(MANDIR)/man$$section; \
 		for manfile in ../doc/*.$$section*; do \
-		    echo $(INSTALL) -m 644 $$manfile $(MANDIR)/man$$section; \
-		    $(INSTALL) -m 644 $$manfile $(MANDIR)/man$$section; \
+		    echo $(INSTALL) -m 644 $$manfile $(DESTROOT)$(MANDIR)/man$$section; \
+		    $(INSTALL) -m 644 $$manfile $(DESTROOT)$(MANDIR)/man$$section; \
 		done ; \
 	done
-	test -n "$(DBM)" || rm -f $(MANDIR)/man8/builddbm.8rad
-	@if [ -d /etc/pam.d/ ] && [ ! -f /etc/pam.d/radius ]; then \
-		$(INSTALL) -m 644 ../redhat/radiusd-pam /etc/pam.d/radius;\
+	test -n "$(DBM)" || rm -f $(DESTROOT)$(MANDIR)/man8/builddbm.8rad
+	@if [ -d $(DESTROOT)${PREFIX}/etc/pam.d/ ] && [ ! -f $(DESTROOT)${PREFIX}/etc/pam.d/radius ]; then \
+		$(INSTALL) -m 644 ../redhat/radiusd-pam $(DESTROOT)${PREFIX}/etc/pam.d/radius;\
 	fi
 	@# Install the config files
 	@echo; echo "Creating/updating files in $(RADIUS_DIR)"; \
 	cd ../raddb; \
 	for i in [a-c]* [e-z]*; do \
-		[ ! -f $(RADIUS_DIR)/$$i ] && cp $$i $(RADIUS_DIR)/$$i; \
+		[ ! -f $(RADIUS_DIR)/$$i ] && cp $$i $(DESTROOT)$(RADIUS_DIR)/$$i.sample; \
 	done; true
 	@# Install the dictionary files
-	@sh dict-install.sh ../raddb $(RADIUS_DIR) $(SHAREDIR)
+	@sh dict-install.sh ../raddb $(RADIUS_DIR) $(DESTROOT)$(SHAREDIR)
 
