Fix some locations specific to the ports tree i.e.

- Fixes location of manpages resulting to be in site_perl
- Set LOCALSTATEDIR to /var/run as done in this ports tree
- Install agent.cfg as agent.cfg.sample

--- Makefile.PL.orig	2015-11-10 20:54:31 UTC
+++ Makefile.PL
@@ -142,22 +142,12 @@ sub constants {
 
     # for some reason, initialising variables from the global scope doesn't work
     %variables = (
-        PREFIX               => '/usr/local',
-        INSTALLSCRIPT        => '$(PREFIX)/bin',
-        INSTALLSITESCRIPT    => '$(PREFIX)/bin',
-        INSTALLVENDORSCRIPT  => '$(PREFIX)/bin',
         INSTALLLIB           => '$(DATADIR)/lib',
         INSTALLSITELIB       => '$(DATADIR)/lib',
         INSTALLVENDORLIB     => '$(DATADIR)/lib',
-        INSTALLMAN1DIR       => '$(PREFIX)/share/man/man1',
-        INSTALLSITEMAN1DIR   => '$(PREFIX)/share/man/man1',
-        INSTALLVENDORMAN1DIR => '$(PREFIX)/share/man/man1',
-        INSTALLMAN3DIR       => '$(PREFIX)/share/man/man3',
-        INSTALLSITEMAN3DIR   => '$(PREFIX)/share/man/man3',
-        INSTALLVENDORMAN3DIR => '$(PREFIX)/share/man/man3',
         SYSCONFDIR           => '$(PREFIX)/etc/fusioninventory',
         DATADIR              => '$(PREFIX)/share/fusioninventory',
-        LOCALSTATEDIR        => '$(PREFIX)/var/fusioninventory',
+        LOCALSTATEDIR        => '/var/run/fusioninventory',
     );
 
     # allow variables defined on command line to override defaults
@@ -205,11 +195,7 @@ sub install {
 
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
