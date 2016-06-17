--- base/contrib.mak.orig	2012-08-08 08:01:36 UTC
+++ base/contrib.mak
@@ -860,3 +860,5 @@ $(DD)picty180.dev : $(cdeskjet_)
 	$(SETPDEV) $(DD)picty180 $(cdeskjet_)
 
 #########################################################################
+
+include $(GLSRCDIR)/epag.contrib.mak
