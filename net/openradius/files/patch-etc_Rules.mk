--- etc/Rules.mk.orig 2024-05-23 14:07:34 UTC
+++ etc/Rules.mk
@@ -13,7 +13,6 @@
 CMD_INSTETC	:= $(CMD_INSTETC) \
 		   $(INST) $(d)/dictionary -m 644 -d $(INST_PREFIX)$(DIR_ETC) \
 		   	   $(d)/subdicts/* -m 644 -d $(INST_PREFIX)$(DIR_ETC)/subdicts \
-			   $(d)/legacy/*   -m 640 -d $(INST_PREFIX)$(DIR_ETC)/legacy \
 			   $(d)/modules/radldap.attrmap \
 			   		   -m 644 -d $(INST_PREFIX)$(DIR_ETC)/modules ; \
 		   cp examples/configuration.sample-usersfile $(INST_PREFIX)$(DIR_ETC)/configuration ; \
