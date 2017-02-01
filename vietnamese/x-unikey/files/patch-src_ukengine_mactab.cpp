--- src/ukengine/mactab.cpp.orig	2006-04-09 11:46:02 UTC
+++ src/ukengine/mactab.cpp
@@ -287,7 +287,7 @@ int CMacroTable::addItem(const char *ite
   char key[MAX_MACRO_KEY_LEN];
   
   // Parse the input item
-  char * pos = strchr(item, ':');
+  const char * pos = strchr(item, ':');
   if (pos == NULL)
     return -1;
   int keyLen = (int)(pos - item);
