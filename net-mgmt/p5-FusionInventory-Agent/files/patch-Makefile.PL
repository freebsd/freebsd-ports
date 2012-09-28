--- Makefile.PL.orig	2012-09-27 23:53:24.000000000 +0000
+++ Makefile.PL	2012-09-27 23:55:38.000000000 +0000
@@ -151,11 +151,7 @@
 
 config_install :
 	install -d -m 755 $(DESTDIR)$(SYSCONFDIR)
-	if [ -f $(DESTDIR)/$(SYSCONFDIR)/agent.cfg ]; then \
-	    install -m 644 etc/agent.cfg $(DESTDIR)$(SYSCONFDIR)/agent.cfg.new; \
-	else \
-	    install -m 644 etc/agent.cfg $(DESTDIR)$(SYSCONFDIR)/agent.cfg; \
-	fi
+	install -m 644 etc/agent.cfg $(DESTDIR)$(SYSCONFDIR)/agent.cfg.sample
 
 data_install :
 	install -d -m 755 $(DESTDIR)$(DATADIR)
