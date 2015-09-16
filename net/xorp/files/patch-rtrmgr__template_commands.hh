--- rtrmgr/template_commands.hh.orig	2012-01-11 17:56:10 UTC
+++ rtrmgr/template_commands.hh
@@ -78,6 +78,8 @@ public:
     string related_module() const;
     string affected_module() const;
 
+    const XRLdb*	_xrldb;
+
 private:
 #ifdef DEBUG_XRLDB
     bool check_xrl_is_valid(const list<string>& action,
@@ -92,7 +94,7 @@ private:
     string		_request;
     list<string>	_split_response;
     string		_response;
-    const XRLdb*	_xrldb;
+    // const XRLdb*	_xrldb;
 };
 
 class ProgramAction : public Action {
