--- ./rtrmgr/template_commands.hh.orig	2011-03-16 21:16:14.000000000 +0000
+++ ./rtrmgr/template_commands.hh	2014-02-26 21:17:13.000000000 +0000
@@ -78,6 +78,8 @@
     string related_module() const;
     string affected_module() const;
 
+    const XRLdb*	_xrldb;
+
 private:
 #ifdef DEBUG_XRLDB
     bool check_xrl_is_valid(const list<string>& action,
@@ -92,7 +94,7 @@
     string		_request;
     list<string>	_split_response;
     string		_response;
-    const XRLdb*	_xrldb;
+    // const XRLdb*	_xrldb;
 };
 
 class ProgramAction : public Action {
