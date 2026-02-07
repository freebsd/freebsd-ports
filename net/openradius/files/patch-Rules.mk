--- Rules.mk.orig 2024-05-23 14:07:34 UTC
+++ Rules.mk
@@ -74,19 +74,6 @@
 		$(CMD_INSTSBIN)
 		$(INST) $(TGT_LIB) -m 755 -d $(INST_PREFIX)$(DIR_LIB)
 		$(CMD_INSTLIB)
-ifeq ($(wildcard $(INST_PREFIX)$(DIR_ETC)/*),)
-		$(INST) $(TGT_ETC) -m 644 -d $(INST_PREFIX)$(DIR_ETC)
-		$(CMD_INSTETC)
-else
-		@echo
-		@echo Configuration directory $(DIR_ETC) already present -- skipping. 
-		@echo
-		@echo When upgrading, is recommended to rename your existing configuration
-		@echo directory $(DIR_ETC) to eg. $(DIR_ETC).orig,
-		@echo to redo the installation, and to copy only the configuration- and behaviour 
-		@echo files and the files in the legacy and modules subdirectories that have 
-		@echo local changes back from the .orig directory.
-endif
 		@echo
 		@echo If no error messages appeared, OpenRADIUS has been installed successfully. 
 		@echo
