--- netmap/hostclass.h.orig
+++ netmap/hostclass.h
@@ -48,10 +48,10 @@
     HostClass* a;
     HostClass* b;
 
-    bool operator==(HostLink& hl)
+    bool operator==(const HostLink& hl) const
 	{ return a == hl.a && b == hl.b; }
 
-    bool operator <(HostLink& hl)
+    bool operator <(const HostLink& hl) const
 	{ return a==hl.a ? b < hl.b : a < hl.a; }
 };
 
