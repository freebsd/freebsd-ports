--- src/hooks/msnhook.cc.orig	Thu Jul  1 03:42:16 2004
+++ src/hooks/msnhook.cc	Thu Jul 29 10:02:57 2004
@@ -155,6 +155,9 @@
     int hsock = 0;
     MSN::Connection *c;
 
+    FD_ZERO(&rs);
+    FD_ZERO(&ws);
+    FD_ZERO(&es);
     getsockets(rs, ws, es, hsock);
     tv.tv_sec = tv.tv_usec = 0;
 
@@ -451,11 +454,11 @@
 
 void msnhook::checkfriendly(icqcontact *c, const string friendlynick, bool forcefetch) {
     string oldnick = c->getnick();
-    string newnick = unmime(friendlynick);
+    string newnick = rusconv("uk",unmime(friendlynick));
 
     c->setnick(newnick);
 
-    if(forcefetch || (oldnick != newnick && c->getdispnick() == oldnick) || oldnick.empty()) {
+    if(forcefetch || (oldnick != newnick && c->getdispnick() != newnick) || oldnick.empty()) {
 	c->setdispnick(newnick);
 	face.relaxedupdate();
     }
