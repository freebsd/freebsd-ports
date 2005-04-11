--- etc/Rules.mk.orig	Thu Mar 31 10:50:37 2005
+++ etc/Rules.mk	Thu Mar 31 10:50:29 2005
@@ -11,9 +11,7 @@
 
 CMD_INSTETC	:= $(CMD_INSTETC) \
 		   $(INST) $(d)/subdicts/* -m 644 -d $(DIR_ETC)/subdicts \
-			   $(d)/modules/* -m 644 -d $(DIR_ETC)/modules \
-			   $(d)/legacy/* -m 640 -d $(DIR_ETC)/legacy ;
-
+			   $(d)/modules/* -m 644 -d $(DIR_ETC)/modules ;
 
 # Standard things
 
