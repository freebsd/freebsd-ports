===================================================================
RCS file: /cvsroot/stone/stone/stone.c,v
retrieving revision 2.3.2.1
retrieving revision 2.3.2.2
diff -u -r2.3.2.1 -r2.3.2.2
--- stone.c	2007/10/05 21:59:48	2.3.2.1
+++ stone.c	2007/10/22 03:07:17	2.3.2.2
@@ -93,7 +93,7 @@
  */
 #define VERSION	"2.3d"
 static char *CVS_ID =
-"@(#) $Id: stone.c,v 2.3.2.1 2007/10/05 21:59:48 hiroaki_sengoku Exp $";
+"@(#) $Id: stone.c,v 2.3.2.2 2007/10/22 03:07:17 hiroaki_sengoku Exp $";
 
 #include <stdio.h>
 #include <stdlib.h>
@@ -3047,9 +3047,6 @@
     time(&pair->clock);
     if (p) p->clock = pair->clock;
     pair->tx += len;
-    if ((pair->xhost->mode & XHostsMode_Dump) > 0
-	|| ((pair->proto & proto_first_w) && Debug > 3))
-	message_buf(pair, len, "UDP");
     return 0;	/* success */
 }
 
@@ -3143,9 +3140,15 @@
 	if (ex != pair->b) ungetExBuf(ex);
 	if (pos >= len) {	/* complete the packet */
 	complete:
-	    if (!err) err = sendPairUDPbuf(stone, pair,
-					   (char*)(buf+UDP_HEAD_LEN),
-					   len-UDP_HEAD_LEN);
+	    if (!err) {
+		err = sendPairUDPbuf(stone, pair, (char*)(buf+UDP_HEAD_LEN),
+				     len-UDP_HEAD_LEN);
+		if (!err) {
+		    if ((pair->xhost->mode & XHostsMode_Dump) > 0
+			|| ((pair->proto & proto_first_w) && Debug > 3))
+			message_buf(pair, len, "tu");
+		}
+	    }
 	    if (cur != pair->b) ungetExBuf(cur);
 	    cur = NULL;
 	}
@@ -3810,7 +3813,11 @@
 	message(LOG_DEBUG, "%d TCP %d: connecting to TCP %d %s",
 		p1->stone->sd, p2->sd, p1->sd, addrport);
     }
-    ret = connect(p1->sd, dst, dstlen);
+    if (p1->proto & proto_dgram) {
+	ret = 0;	/* do nothing */
+    } else {
+	ret = connect(p1->sd, dst, dstlen);
+    }
     if (ret < 0) {
 #ifdef WINDOWS
 	errno = WSAGetLastError();
