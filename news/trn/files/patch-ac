--- Makefile.SH.orig	Thu Jun  4 10:49:20 1998
+++ Makefile.SH	Thu Jun  4 10:49:50 1998
@@ -133,6 +133,7 @@
 # won't work with csh
 	export PATH || exit 1
 	- (cd `./filexp $(rnbin)`; mv trn trn.old)
+	- (cd `./filexp $(rnbin)`; rm trn.old)
 	- if test `pwd` != `./filexp $(rnbin)`; then cp $(public) `./filexp $(rnbin)`;\
  (cd `./filexp $(rnbin)`; chmod o+x $(public); strip trn trn-artchk $(nntpbin)); fi
 	- if test $(installfilexp) = Rnfilexp; then cp ./filexp `./filexp $(rnbin)/Rnfilexp`; fi
