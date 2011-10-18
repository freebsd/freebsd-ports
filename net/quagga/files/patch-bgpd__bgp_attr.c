--- ./bgpd/bgp_attr.c.orig	2011-10-18 10:12:39.000000000 -0400
+++ ./bgpd/bgp_attr.c	2011-10-18 10:13:01.000000000 -0400
@@ -675,6 +675,7 @@
     }
 
   bgp_attr_unintern_sub (&tmp);
+  bgp_attr_extra_free (&tmp);
 }
 
 void
