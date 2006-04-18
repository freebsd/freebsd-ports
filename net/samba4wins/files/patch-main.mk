--- main.mk.orig	Sun Apr  9 04:52:10 2006
+++ main.mk	Sun Apr  9 04:52:33 2006
@@ -86,8 +86,7 @@
 	 -DMODULESDIR=\"$(MODULESDIR)\" -DJSDIR=\"$(JSDIR)\" \
 	 -DSETUPDIR=\"$(SETUPDIR)\"
 
-install: showlayout installbin installdat installswat installmisc installlib \
-	installheader installpc
+install: showlayout installbin installdat installmisc installlib installpc
 
 # DESTDIR is used here to prevent packagers wasting their time
 # duplicating the Makefile. Remove it and you will have the privilege
