--- Makefile.PL.orig	2024-08-04 21:46:10 UTC
+++ Makefile.PL
@@ -164,25 +164,15 @@ sub constants {
 
     # for some reason, initialising variables from the global scope doesn't work
     %variables = (
-        PREFIX               => '/usr/local',
         VERSION              => '',
         COMMENTS             => "Platform  : $Config{myuname},Build date: ".gmtime()." (GMT)",
         RAWCOMMENTS          => '',
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
@@ -244,14 +234,9 @@ config_install : pure_install
 	$(NOECHO) $(CHMOD) $(PERM_DIR) $(DESTDIR)$(SYSCONFDIR)
 	for config in agent.cfg $(shell cd etc; echo *-plugin.cfg ); \
 	do \
-	  if $(TEST_F) $(DESTDIR)$(SYSCONFDIR)/$$config; then \
 	    $(RM_F) $(DESTDIR)$(SYSCONFDIR)/$$config.new; \
 	    $(CP) etc/$$config $(DESTDIR)$(SYSCONFDIR)/$$config.new; \
 	    $(CHMOD) $(PERM_RW) $(DESTDIR)$(SYSCONFDIR)/$$config.new; \
-	  else \
-	    $(CP) etc/$$config $(DESTDIR)$(SYSCONFDIR)/$$config; \
-	    $(CHMOD) $(PERM_RW) $(DESTDIR)$(SYSCONFDIR)/$$config; \
-	  fi; \
 	done
 	$(ABSPERLRUN) -pi \
 	    -e "s|=> undef, # SYSCONFDIR.*|=> '$(SYSCONFDIR)',|;" \
