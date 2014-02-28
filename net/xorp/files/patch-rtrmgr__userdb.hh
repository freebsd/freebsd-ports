--- ./rtrmgr/userdb.hh.orig	2011-03-16 21:16:14.000000000 +0000
+++ ./rtrmgr/userdb.hh	2014-02-26 21:17:13.000000000 +0000
@@ -98,6 +98,7 @@
 
 private:
     map<uid_t, User*> _users;
+public:
     bool _verbose;	// Set to true if output is verbose
 };
 
