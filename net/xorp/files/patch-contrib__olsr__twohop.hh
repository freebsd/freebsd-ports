--- ./contrib/olsr/twohop.hh.orig	2011-03-16 21:27:46.000000000 +0000
+++ ./contrib/olsr/twohop.hh	2014-02-26 21:17:13.000000000 +0000
@@ -140,8 +140,10 @@
 	return _twohop_links;
     }
 
-  private:
     EventLoop&		    _ev;
+
+  private:
+    // EventLoop&		    _ev;
     Neighborhood*	    _parent;
 
     /**
