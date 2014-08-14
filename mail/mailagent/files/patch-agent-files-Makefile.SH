--- ./agent/files/Makefile.SH.orig	2006-08-24 22:24:12.000000000 +0900
+++ ./agent/files/Makefile.SH	2014-08-14 01:59:33.532955007 +0900
@@ -87,7 +87,7 @@
 install::
 	@for dir in $(PRIVLIB); do \
 	case '${MFLAGS}' in *[i]*) set +e;; esac; \
-	(set -x; test -d $$dir || $(INSTALLDIR) $$dir); \
+	(set -x; test -d $(INSTALL_PREFIX)$$dir || $(INSTALLDIR) $(INSTALL_PREFIX)$$dir); \
 	done
 
 deinstall::
@@ -96,7 +96,7 @@
 install:: $(FILES)
 	@case '${MFLAGS}' in *[i]*) set +e;; esac; \
 	for i in $(FILES); do \
-	(set -x; $(INSTALL) -c -m 444 $$i $(PRIVLIB)); \
+	(set -x; $(INSTALL) -c -m 444 $$i $(INSTALL_PREFIX)$(PRIVLIB)); \
 	done
 
 deinstall::
