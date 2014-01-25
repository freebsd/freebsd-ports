--- netmap/lookup.h.orig
+++ netmap/lookup.h
@@ -14,10 +14,10 @@
     string ip;
     string hostname;
 
-    bool operator==(const HostRec& hr)
+    bool operator==(const HostRec& hr) const
 	{ return ip == hr.ip && hostname == hr.hostname; }
 
-    bool operator<(const HostRec& hr)
+    bool operator<(const HostRec& hr) const
 	{ return ip==hr.ip ? hostname<hr.hostname : ip<hr.ip; }
 };
 
