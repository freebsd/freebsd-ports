--- ./golded3/gehdre.cpp.orig	Mon Oct 20 02:57:23 2003
+++ ./golded3/gehdre.cpp	Mon Oct 20 02:58:21 2003
@@ -511,7 +511,7 @@
       // Try to match akas with the dest address, but only if the orig address was NOT changed
       vector<gaka>::iterator i;
       for(i = CFG->aka.begin(); i != CFG->aka.end(); i++) {
-        if(memcmp(&msg->orig, i, sizeof(Addr)) == 0)
+        if(memcmp(&msg->orig, &(*i), sizeof(Addr)) == 0)
           break;  // Found one of our own akas.
       }
 
