--- agent/man/Makefile.SH.orig	Sun Mar 18 03:31:22 2001
+++ agent/man/Makefile.SH	Tue Sep  3 07:51:50 2002
@@ -85,8 +85,7 @@
 # Baseline for mailagent 3.0 netwide release.
 #
 
-MPAGES = mailagent.$(L) maildist.$(L) maillist.$(L) mailhelp.$(L) \
-	mailpatch.$(L) package.$(L) edusers.$(L)
+MPAGES = mailagent.$(L) mailhelp.$(L) package.$(L) edusers.$(L)
 
 all:: $(MPAGES)
 
