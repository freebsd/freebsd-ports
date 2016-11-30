--- Source/util.cpp.orig	2005-08-11 14:32:00 UTC
+++ Source/util.cpp
@@ -523,7 +523,7 @@ char *sgettext (const char *msgid)
   char *msgval = gettext (msgid);
   if (msgval == msgid)
   {
-    msgval = strrchr (msgid, '|');
+    msgval = strrchr ((char *) msgid, '|');
     if(!msgval)
       msgval = (char *) msgid;
     else
@@ -536,7 +536,7 @@ char *sgettext (const char *msgid)
 
 char *sgettext_strip(const char *msgid)
 {
-  char *msgval = strrchr(msgid, '|');
+  char *msgval = strrchr((char *) msgid, '|');
   if(!msgval)
     return (char *) msgid;
 
