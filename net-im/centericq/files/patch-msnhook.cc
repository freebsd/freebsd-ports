--- src/hooks/msnhook.cc.orig	Tue Sep 30 19:38:43 2003
+++ src/hooks/msnhook.cc	Wed Oct  8 17:44:13 2003
@@ -248,7 +248,7 @@
     }
 
     icqcontact *c = clist.get(ev.getcontact());
-    text = siconv(text, conf.getrussian(msn) ? "koi8-u" : conf.getdefcharset(), "utf8");
+    text = siconv(text, conf.getrussian(msn) ? "koi8-u" : conf.getdefcharset(), "utf-8");
 
     if(c)
     if(c->getstatus() != offline || !c->inlist()) {
@@ -378,11 +378,11 @@
 
 void msnhook::checkfriendly(icqcontact *c, const string friendlynick, bool forcefetch) {
     string oldnick = c->getnick();
-    string newnick = unmime(friendlynick);
+    string newnick = siconv(unmime(friendlynick), "utf-8", conf.getrussian(msn) ? "koi8-u" : conf.getdefcharset());
 
     c->setnick(newnick);
 
-    if(forcefetch || (oldnick != newnick && c->getdispnick() == oldnick) || oldnick.empty()) {
+    if(forcefetch || (oldnick != newnick && c->getdispnick() != oldnick) || oldnick.empty()) {
 	c->setdispnick(newnick);
 	face.relaxedupdate();
     }
@@ -602,7 +602,7 @@
 
     mhook.checkinlist(ic);
 
-    string text = siconv(msg->body, "utf8", conf.getrussian(msn) ? "koi8-u" : conf.getdefcharset());
+    string text = siconv(msg->body, "utf-8", conf.getrussian(msn) ? "koi8-u" : conf.getdefcharset());
     em.store(immessage(ic, imevent::incoming, text));
 }
 
