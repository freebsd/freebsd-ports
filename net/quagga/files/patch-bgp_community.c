--- bgpd/bgp_community.c.orig	2008-09-05 22:27:26.000000000 +0800
+++ bgpd/bgp_community.c	2009-04-30 16:33:56.000000000 +0800
@@ -282,7 +282,7 @@
 	default:
 	  as = (comval >> 16) & 0xFFFF;
 	  val = comval & 0xFFFF;
-	  sprintf (pnt, "%d:%d", as, val);
+	  sprintf (pnt, "%u:%d", as, val);
 	  pnt += strlen (pnt);
 	  break;
 	}
