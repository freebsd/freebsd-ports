--- src/hooks/msnhook.cc.orig	Sun Mar  7 21:44:41 2004
+++ src/hooks/msnhook.cc	Fri Apr  2 10:23:03 2004
@@ -408,11 +408,11 @@
 
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
