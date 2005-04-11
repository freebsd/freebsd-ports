--- Rules.mk.orig	Thu Mar 31 10:55:15 2005
+++ Rules.mk	Thu Mar 31 10:55:43 2005
@@ -69,12 +69,7 @@
 		$(CMD_INSTBIN)
 		$(INST) $(TGT_SBIN) -m 750 -d $(DIR_SBIN)
 		$(CMD_INSTSBIN)
-ifeq ($(wildcard $(DIR_ETC)/*),)
-		$(INST) $(TGT_ETC) -m 644 -d $(DIR_ETC)
 		$(CMD_INSTETC)
-else
-		@echo Configuration directory $(DIR_ETC) already present -- skipping
-endif
 		$(INST) $(TGT_LIB) -m 750 -d $(DIR_LIB)
 		$(CMD_INSTLIB)
 		@echo
