--- gnome-im-switcher/help/omf.make.orig	Thu Sep 23 06:31:15 2004
+++ gnome-im-switcher/help/omf.make		Sun May 29 22:04:45 2005
@@ -26,7 +26,7 @@
 # 	Version: 0.1.3 (last updated: March 20, 2002)
 #
 
-omf_dest_dir=$(datadir)/omf/@PACKAGE@
+omf_dest_dir=$(datadir)/gnome/omf/@PACKAGE@
 scrollkeeper_localstate_dir = $(localstatedir)/scrollkeeper
 
 # At some point, it may be wise to change to something like this:
@@ -45,7 +45,9 @@
 	for file in $(omffile); do \
 		$(INSTALL_DATA) $$file.out $(DESTDIR)$(omf_dest_dir)/$$file; \
 	done
-	-scrollkeeper-update -p $(scrollkeeper_localstate_dir) -o $(DESTDIR)$(omf_dest_dir)
+	-for file in $(omffile); do \
+		scrollkeeper-install $(DESTDIR)$(omf_dest_dir)/$$file; \
+	done
 
 uninstall-local-omf:
 	-for file in $(srcdir)/*.omf; do \
@@ -53,7 +55,9 @@
 		rm -f $(omf_dest_dir)/$$basefile; \
 	done
 	-rmdir $(omf_dest_dir)
-	-scrollkeeper-update -p $(scrollkeeper_localstate_dir)
+	-for file in $(omffile); do \
+		scrollkeeper-uninstall $(DESTDIR)$(omf_dest_dir)/$$file; \
+	done
 
 clean-local-omf:
 	-for file in $(omffile); do \
