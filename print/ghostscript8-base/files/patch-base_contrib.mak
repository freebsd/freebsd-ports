--- base/contrib.mak.orig	2009-04-28 22:11:03 UTC
+++ base/contrib.mak
@@ -858,3 +858,5 @@ $(DD)picty180.dev : $(cdeskjet_)
 	$(SETPDEV) $(DD)picty180 $(cdeskjet_)
 
 #########################################################################
+
+include $(GLSRCDIR)/epag.contrib.mak
