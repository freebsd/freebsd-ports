--- vrrp/vrrp.cc.orig	2012-01-11 17:56:10 UTC
+++ vrrp/vrrp.cc
@@ -36,7 +36,7 @@ namespace {
 
 template <class T>
 void
-out_of_range(const string& msg, const T& x)
+out_of_range_(const string& msg, const T& x)
 {
     ostringstream oss;
 
@@ -64,7 +64,7 @@ Vrrp::Vrrp(VrrpVif& vif, EventLoop& e, u
       //, _arpd(_vif)
 {
     if (_vrid < 1 || _vrid > 255)
-	out_of_range("VRID out of range", _vrid);
+	out_of_range_("VRID out of range", _vrid);
 
     char tmp[sizeof "ff:ff:ff:ff:ff:ff"];
 
@@ -94,7 +94,7 @@ void
 Vrrp::set_priority(uint32_t priority)
 {
     if (priority == PRIORITY_LEAVE || priority >= PRIORITY_OWN)
-	out_of_range("priority out of range", priority);
+	out_of_range_("priority out of range", priority);
 
     _priority = priority;
 
