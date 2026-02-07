--- ./agent/examples/Makefile.SH.orig	2006-08-24 22:24:12.000000000 +0900
+++ ./agent/examples/Makefile.SH	2014-08-14 01:59:33.512702931 +0900
@@ -84,7 +84,7 @@
 install::
 	@for dir in $(PRIVLIB)/examples; do \
 	case '${MFLAGS}' in *[i]*) set +e;; esac; \
-	(set -x; test -d $$dir || $(INSTALLDIR) $$dir); \
+	(set -x; test -d $(INSTALL_PREFIX)$$dir || $(INSTALLDIR) $(INSTALL_PREFIX)$$dir); \
 	done
 
 deinstall::
@@ -93,7 +93,7 @@
 install:: $(FILES)
 	@case '${MFLAGS}' in *[i]*) set +e;; esac; \
 	for i in $(FILES); do \
-	(set -x; $(INSTALL) -c -m 444 $$i $(PRIVLIB)/examples); \
+	(set -x; $(INSTALL) -c -m 444 $$i $(INSTALL_PREFIX)$(PRIVLIB)/examples); \
 	done
 
 deinstall::
