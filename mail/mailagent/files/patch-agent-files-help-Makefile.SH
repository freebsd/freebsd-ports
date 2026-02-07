--- ./agent/files/help/Makefile.SH.orig	2006-08-24 22:24:12.000000000 +0900
+++ ./agent/files/help/Makefile.SH	2014-08-14 01:59:33.534704805 +0900
@@ -129,7 +129,7 @@
 install::
 	@for dir in $(PRIVLIB) $(PRIVLIB)/help; do \
 		case '${MFLAGS}' in *[i]*) set +e;; esac; \
-		(set -x; test -d $$dir || $(INSTALLDIR) $$dir); \
+		(set -x; test -d $(INSTALL_PREFIX)$$dir || $(INSTALLDIR) $(INSTALL_PREFIX)$$dir); \
 	done
 
 deinstall::
@@ -138,7 +138,7 @@
 install:: $(FILES)
 	@case '${MFLAGS}' in *[i]*) set +e;; esac; \
 	for i in $(FILES); do \
-		(set -x; $(INSTALL) -c -m 444 $$i $(PRIVLIB)/help); \
+		(set -x; $(INSTALL) -c -m 444 $$i $(INSTALL_PREFIX)$(PRIVLIB)/help); \
 	done
 
 deinstall::
