--- ./golded3/gepost.cpp.orig	Mon Oct 20 03:09:41 2003
+++ ./golded3/gepost.cpp	Mon Oct 20 03:10:16 2003
@@ -243,7 +243,7 @@
   msg->oorig = msg->orig;
   if(AA->isnet() and msg->orig.point) {
     for(u = CFG->aka.begin(); u != CFG->aka.end(); u++) {
-      if(not memcmp(u, &msg->orig, sizeof(Addr))) {
+      if(not memcmp(&(*u), &msg->orig, sizeof(Addr))) {
         // Use fakenet to everybody
         if(u->pointnet) {
           msg->oorig.net   = u->pointnet;  // Create fake address
@@ -361,7 +361,7 @@
       cmsg->oorig = cmsg->orig;
       if(AA->isnet() and cmsg->orig.point) {
         for(u = CFG->aka.begin(); u != CFG->aka.end(); u++) {
-          if(not memcmp(u, &cmsg->orig, sizeof(Addr))) {
+          if(not memcmp(&(*u), &cmsg->orig, sizeof(Addr))) {
             // Use fakenet to everybody
             if(u->pointnet) {
               cmsg->oorig.net   = u->pointnet;  // Create fake address
