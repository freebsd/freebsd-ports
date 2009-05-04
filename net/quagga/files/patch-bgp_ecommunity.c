--- bgpd/bgp_ecommunity.c.orig	2008-09-05 22:27:26.000000000 +0800
+++ bgpd/bgp_ecommunity.c	2009-04-30 16:33:56.000000000 +0800
@@ -673,7 +673,7 @@
 	  eas.val = (*pnt++ << 8);
 	  eas.val |= (*pnt++);
 
-	  len = sprintf( str_buf + str_pnt, "%s%d:%d", prefix,
+	  len = sprintf( str_buf + str_pnt, "%s%u:%d", prefix,
                         eas.as, eas.val );
 	  str_pnt += len;
 	  first = 0;
@@ -688,7 +688,7 @@
 	  eas.val |= (*pnt++ << 8);
 	  eas.val |= (*pnt++);
 
-	  len = sprintf (str_buf + str_pnt, "%s%d:%d", prefix,
+	  len = sprintf (str_buf + str_pnt, "%s%u:%d", prefix,
 			 eas.as, eas.val);
 	  str_pnt += len;
 	  first = 0;
