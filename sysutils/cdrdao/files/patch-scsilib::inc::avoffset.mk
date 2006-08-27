--- scsilib/inc/avoffset.mk.orig	Sun Jul 13 00:55:06 2003
+++ scsilib/inc/avoffset.mk	Fri Aug 25 13:34:32 2006
@@ -15,3 +15,5 @@
 ###########################################################################
 include		$(SRCROOT)/$(RULESDIR)/rules.inc
 ###########################################################################
+
+.IGNORE:	$(PTARGET)
