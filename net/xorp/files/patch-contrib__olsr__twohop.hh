--- contrib/olsr/twohop.hh.orig	2012-01-11 17:56:10 UTC
+++ contrib/olsr/twohop.hh
@@ -140,8 +140,10 @@ class TwoHopNeighbor {
 	return _twohop_links;
     }
 
-  private:
     EventLoop&		    _ev;
+
+  private:
+    // EventLoop&		    _ev;
     Neighborhood*	    _parent;
 
     /**
