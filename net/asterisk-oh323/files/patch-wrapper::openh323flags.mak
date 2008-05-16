--- wrapper/openh323flags.mak.orig	2008-03-20 16:49:39.000000000 +0200
+++ wrapper/openh323flags.mak	2008-05-16 11:18:00.000000000 +0300
@@ -1,6 +1,9 @@
 
 include $(OPENH323DIR)/openh323u.mak
 
+obj_r/*.dep:
+	@true # suppress implicit rule
+
 oh323ccflags:
 	@echo $(STDCCFLAGS)
 
