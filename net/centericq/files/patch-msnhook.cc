--- src/hooks/msnhook.cc.orig	Tue Sep 30 19:38:43 2003
+++ src/hooks/msnhook.cc	Thu Oct 23 20:12:58 2003
@@ -120,11 +120,14 @@
 
     face.log(_("+ [msn] connecting to the server"));
 
+    flogged = false;
+    fonline = true;
+
     msn_init(&conn, nicknormalize(account.nickname).c_str(), account.password.c_str());
     msn_connect(&conn, account.server.c_str(), account.port);
 
     fonline = true;
-    flogged = false;
+    flogged = true;
 }
 
 void msnhook::disconnect() {
@@ -248,7 +251,7 @@
     }
 
     icqcontact *c = clist.get(ev.getcontact());
-    text = siconv(text, conf.getrussian(msn) ? "koi8-u" : conf.getdefcharset(), "utf8");
+    text = siconv(text, conf.getrussian(msn) ? "koi8-u" : conf.getdefcharset(), "utf-8");
 
     if(c)
     if(c->getstatus() != offline || !c->inlist()) {
@@ -378,11 +381,11 @@
 
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
@@ -450,6 +453,12 @@
 #endif
 }
 
+int ext_debug( char *str )
+{
+    log( str );
+    return 0;
+}
+
 void ext_register_sock(int s, int reading, int writing) {
     log("ext_register_sock");
     if(reading) mhook.rfds.push_back(s);
@@ -602,7 +611,7 @@
 
     mhook.checkinlist(ic);
 
-    string text = siconv(msg->body, "utf8", conf.getrussian(msn) ? "koi8-u" : conf.getdefcharset());
+    string text = siconv(msg->body, "utf-8", conf.getrussian(msn) ? "koi8-u" : conf.getdefcharset());
     em.store(immessage(ic, imevent::incoming, text));
 }
 
@@ -710,8 +719,7 @@
     log("ext_changed_state");
 }
 
-int ext_connect_socket(const char *hostname, int port) {
-    log("ext_connect_socket");
+int ext_do_connect_socket(const char *hostname, int port, int ssl) {
     struct sockaddr_in sa;
     struct hostent *hp;
     int a, s;
@@ -732,13 +740,23 @@
     if((s = socket(hp->h_addrtype, SOCK_STREAM, 0)) < 0)
 	return -1;
 
-    if(cw_connect(s, (struct sockaddr *) &sa, sizeof(sa), 0) < 0) {
+    if(cw_connect(s, (struct sockaddr *) &sa, sizeof(sa), ssl) < 0) {
 	face.log(msgerr + _("verify the hostname and port"));
 	close(s);
 	return -1;
     }
 
     return s;
+}
+
+int ext_connect_socket_ssl(const char *hostname, int port) {
+        log("ext_connect_socket_ssl");
+        return ext_do_connect_socket(hostname, port, 1);
+}
+
+int ext_connect_socket(const char *hostname, int port) {
+        log("ext_connect_socket");
+        return ext_do_connect_socket(hostname, port, 0);
 }
 
 int ext_server_socket(int port) {
