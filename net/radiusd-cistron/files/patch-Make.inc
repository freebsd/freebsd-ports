--- src/Make.inc.orig	Thu Apr 10 12:51:47 2003
+++ src/Make.inc	Wed Jun 25 17:24:21 2003
@@ -4,7 +4,7 @@
 #
 #
 
-RADIUS_DIR    = /etc/raddb
+RADIUS_DIR    = ${PREFIX}/etc/raddb
 
 SERVER_OBJS   = radiusd.o files.o acct.o pam.o version.o proxy.o \
 			exec.o auth.o timestr.o cache.o readusers.o
@@ -143,7 +143,7 @@
 	@echo; echo "Creating/updating files in $(RADIUS_DIR)"; \
 	cd ../raddb; \
 	for i in [a-c]* [e-z]*; do \
-		[ ! -f $(RADIUS_DIR)/$$i ] && cp $$i $(RADIUS_DIR)/$$i; \
+		[ ! -f $(RADIUS_DIR)/$$i ] && cp $$i $(RADIUS_DIR)/$$i.sample; \
 	done; true
 	@# Install the dictionary files
 	@sh dict-install.sh ../raddb $(RADIUS_DIR) $(SHAREDIR)
