--- rtrmgr/userdb.hh.orig	2012-01-11 17:56:10 UTC
+++ rtrmgr/userdb.hh
@@ -98,6 +98,7 @@ public:
 
 private:
     map<uid_t, User*> _users;
+public:
     bool _verbose;	// Set to true if output is verbose
 };
 
