--- Makefile.PL.orig	Sat Aug 17 18:15:35 2002
+++ Makefile.PL	Sat Aug 17 18:18:22 2002
@@ -125,6 +125,7 @@
              '		$(INST_MAN5DIR) $(INSTALLMAN5DIR)';
  
   $inherited =~ s/(\$\(INSTALLMAN1DIR\))/$1$man5/gm;
+  $inherited =~ s/(\$\(INSTALLSITEMAN1DIR\))/$1$man5/gm;
   $inherited =~ s/install :: all pure_install doc_install/install :: all pure_install doc_install install_razor_agents/;
   $inherited .= "\ninstall_razor_agents::\n\t " . '$(INST_SCRIPT)/razor-client'; 
   $inherited;
