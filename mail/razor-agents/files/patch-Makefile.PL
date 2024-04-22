--- Makefile.PL.orig	2015-04-22 13:28:54 UTC
+++ Makefile.PL
@@ -58,9 +58,9 @@ MAN5PODS = docs/razor-agent.conf.pod \
 	   docs/razor-whitelist.pod  \
 	   docs/razor-agents.pod
 INST_MAN5DIR = blib/man5
-INSTALLMAN5DIR = $(DESTDIR)$(PREFIX)/share/man/man5
-INSTALLSITEMAN5DIR = $(DESTDIR)$(SITEPREFIX)/share/man/man5
-INSTALLVENDORMAN5DIR = $(DESTDIR)$(VENDORPREFIX)/share/man/man5
+DESTINSTALLMAN5DIR = $(DESTDIR)$(PREFIX)/share/man/man5
+DESTINSTALLSITEMAN5DIR = $(DESTDIR)$(SITEPREFIX)/share/man/man5
+DESTINSTALLVENDORMAN5DIR = $(DESTDIR)$(VENDORPREFIX)/share/man/man5
 MAN5EXT = 5
 # end razor-agents
 
@@ -139,10 +139,7 @@ sub MY::install {
   my $self = shift;
   my $inherited = $self->SUPER::install(@_);
 
-  my $man5 = q{ \\
-		$(INST_MAN5DIR) $(INSTALLMAN5DIR)};
-
-  $inherited =~ s/(\$\((?:DEST)?INSTALL\w*MAN1DIR\))/$1$man5/gm;
+  $inherited =~ s/(^\s*"?\$\(INST_MAN)3(DIR"?.*MAN)3(DIR\)"?)/${1}3${2}3$3 \\\n${1}5${2}5$3/gm;
 
   return $inherited;
 }
