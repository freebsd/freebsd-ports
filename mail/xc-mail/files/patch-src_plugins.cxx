--- src/plugins.cxx.orig	Wed Aug 17 10:20:39 2005
+++ src/plugins.cxx	Wed Aug 17 10:21:42 2005
@@ -547,7 +547,7 @@
 
 // -------------------------------------------------------------------------
 
-mainplugin::mainplugin(char *name,char *author,unsigned int flags=0,char *information=NULL) : plugins(name,author,PT_Maintool,flags,information)
+mainplugin::mainplugin(char *name,char *author,unsigned int flags,char *information) : plugins(name,author,PT_Maintool,flags,information)
 {
 }
 mainplugin::mainplugin(class mainplugin *m) : plugins(m)
@@ -595,7 +595,7 @@
 
 // -------------------------------------------------------------------------
 
-newmailplugin::newmailplugin(char *name,char *author,unsigned int flags=0,char *information=NULL) : plugins(name,author,PT_Newmailtool,flags,information)
+newmailplugin::newmailplugin(char *name,char *author,unsigned int flags,char *information) : plugins(name,author,PT_Newmailtool,flags,information)
 {
 }
 newmailplugin::newmailplugin(class newmailplugin *m) : plugins(m)
@@ -636,7 +636,7 @@
 
 // -------------------------------------------------------------------------
 
-showmailplugin::showmailplugin(char *name,char *author,unsigned int flags=0,char *information=NULL) : plugins(name,author,PT_Showmailtool,flags,information)
+showmailplugin::showmailplugin(char *name,char *author,unsigned int flags,char *information) : plugins(name,author,PT_Showmailtool,flags,information)
 {
 }
 showmailplugin::showmailplugin(class showmailplugin *m) : plugins(m)
