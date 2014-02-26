--- ./vrrp/vrrp.cc.orig	2011-03-16 21:27:57.000000000 +0000
+++ ./vrrp/vrrp.cc	2014-02-26 21:17:13.000000000 +0000
@@ -36,7 +36,7 @@
 
 template <class T>
 void
-out_of_range(const string& msg, const T& x)
+out_of_range_(const string& msg, const T& x)
 {
     ostringstream oss;
 
@@ -64,7 +64,7 @@
       //, _arpd(_vif)
 {
     if (_vrid < 1 || _vrid > 255)
-	out_of_range("VRID out of range", _vrid);
+	out_of_range_("VRID out of range", _vrid);
 
     char tmp[sizeof "ff:ff:ff:ff:ff:ff"];
 
@@ -94,7 +94,7 @@
 Vrrp::set_priority(uint32_t priority)
 {
     if (priority == PRIORITY_LEAVE || priority >= PRIORITY_OWN)
-	out_of_range("priority out of range", priority);
+	out_of_range_("priority out of range", priority);
 
     _priority = priority;
 
