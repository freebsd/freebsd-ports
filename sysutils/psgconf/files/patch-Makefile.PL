--- ./Makefile.PL.orig	Mon Jun 26 22:05:42 2006
+++ ./Makefile.PL	Thu Feb  1 09:40:51 2007
@@ -18,8 +18,8 @@
 
 my ($etc_dir, $share_dir);
 
-$etc_dir	= '/etc';
-$share_dir	= '/usr/local/share/psgconf';
+$etc_dir	= '$(PREFIX)/etc';
+$share_dir	= '$(PREFIX)/share/psgconf';
 
 GetOptions(
 	'etcdir=s'		=> \$etc_dir,
@@ -39,7 +39,7 @@
 	$(CP) files/rc.shutdown $(DESTDIR)$(SHARE_DIR)/files
 	$(CP) files/magic $(DESTDIR)$(SHARE_DIR)/files
 
-	$(SH) MAKE=$(MAKE) ROOT_PATH=$(DESTDIR) ETC_DIR=$(ETC_DIR) ./postinstall
+#	$(SH) MAKE=$(MAKE) ROOT_PATH=$(DESTDIR) ETC_DIR=$(ETC_DIR) ./postinstall
 
 svr4pkg:
 	$(MAKE) DESTDIR=$(DESTDIR) install
