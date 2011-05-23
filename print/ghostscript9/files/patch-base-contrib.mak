--- base/contrib.mak.orig	2008-03-04 06:06:45.000000000 +0900
+++ base/contrib.mak	2008-03-04 06:07:11.000000000 +0900
@@ -858,3 +858,5 @@
 	$(SETPDEV) $(DD)picty180 $(cdeskjet_)
 
 #########################################################################
+
+include $(GLSRCDIR)/epag.contrib.mak
