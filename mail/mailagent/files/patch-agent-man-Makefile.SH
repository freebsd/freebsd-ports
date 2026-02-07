--- ./agent/man/Makefile.SH.orig	2006-08-24 22:24:12.000000000 +0900
+++ ./agent/man/Makefile.SH	2014-08-14 01:59:33.542700970 +0900
@@ -85,8 +85,7 @@
 # Baseline for mailagent 3.0 netwide release.
 #
 
-MPAGES = mailagent.$(L) maildist.$(L) maillist.$(L) mailhelp.$(L) \
-	mailpatch.$(L) package.$(L) edusers.$(L)
+MPAGES = mailagent.$(L) mailhelp.$(L) package.$(L) edusers.$(L)
 
 all:: $(MPAGES)
 
