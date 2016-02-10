--- Makefile.SH.orig	1994-11-19 06:01:14 UTC
+++ Makefile.SH
@@ -35,7 +35,6 @@ TOUCH = touch
 lintflags = -phbvxac $vincludes
 
 CFLAGS = $optimize $ccflags $vincludes
-LDFLAGS = $ldflags
 
 rnbin = $installbin
 rnlib = $installprivlib
@@ -133,6 +132,7 @@ install: $(public) $(private) $(manpages
 # won't work with csh
 	export PATH || exit 1
 	- (cd `./filexp $(rnbin)`; mv trn trn.old)
+	- (cd `./filexp $(rnbin)`; rm trn.old)
 	- if test `pwd` != `./filexp $(rnbin)`; then cp $(public) `./filexp $(rnbin)`;\
  (cd `./filexp $(rnbin)`; chmod o+x $(public); strip trn trn-artchk $(nntpbin)); fi
 	- if test $(installfilexp) = Rnfilexp; then cp ./filexp `./filexp $(rnbin)/Rnfilexp`; fi
