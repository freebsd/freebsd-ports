--- ./agent/filter/Makefile.SH.orig	2006-08-24 22:24:12.000000000 +0900
+++ ./agent/filter/Makefile.SH	2014-08-14 01:59:33.536704870 +0900
@@ -154,14 +154,14 @@
 install::
 	@for dir in $(PRIVLIB); do \
 	case '${MFLAGS}' in *[i]*) set +e;; esac; \
-	(set -x; test -d $$dir || $(INSTALLDIR) $$dir); \
+	(set -x; test -d $(INSTALL_PREFIX)$$dir || $(INSTALLDIR) $(INSTALL_PREFIX)$$dir); \
 	done
 
 deinstall::
 	$(RM) -r $(PRIVLIB)
 
 install:: filter
-	$(INSTALL) -c -s -m 555  filter $(PRIVLIB)
+	$(INSTALL) -c -s -m 555  filter $(INSTALL_PREFIX)$(PRIVLIB)
 
 deinstall::
 	$(RM) $(PRIVLIB)/filter
