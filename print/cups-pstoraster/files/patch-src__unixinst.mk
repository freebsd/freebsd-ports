--- src/unixinst.mak.orig	Fri Dec  1 21:54:25 2006
+++ src/unixinst.mak	Fri Dec  1 21:55:49 2006
@@ -18,7 +18,7 @@
 # containing the `install' targets.
 # This is the very last part of the makefile for these configurations.
 
-install: install-exec install-scripts install-data $(INSTALL_SHARED) install-addons-extras
+install: install-exec install-data $(INSTALL_SHARED) install-addons-extras
 
 # The sh -c in the rules below is required because Ultrix's implementation
 # of sh -e terminates execution of a command if any error occurs, even if
@@ -53,7 +53,7 @@
 PSEXDIR=$(PSLIBDIR)/../examples
 PSMANDIR=$(PSLIBDIR)/../man
 
-install-data: install-libdata install-resdata install-doc install-man install-examples
+install-data: install-libdata install-resdata
 
 # There's no point in providing a complete dependency list: we include
 # one file from each subdirectory just as a sanity check.
