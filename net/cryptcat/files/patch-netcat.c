--- netcat.c.orig	2005-10-18 10:42:05.000000000 -0700
+++ netcat.c	2023-05-25 02:08:35.476614000 -0700
@@ -48,9 +48,6 @@
 #else
 #include <malloc.h>
 #endif
-#ifdef HAVE_SELECT_H		/* random SV variants need this */
-#include <sys/select.h>
-#endif
 
 /* have to do this *before* including types.h. xxx: Linux still has it wrong */
 #ifdef FD_SETSIZE		/* should be in types.h, butcha never know. */
@@ -58,6 +55,12 @@
 #endif				/* fd's, something is horribly wrong! */
 #define FD_SETSIZE 16		/* <-- this'll give us a long anyways, wtf */
 #include <sys/types.h>		/* *now* do it.  Sigh, this is broken */
+#ifdef __FreeBSD__
+#include <inttypes.h>
+#endif
+#ifdef HAVE_SELECT_H           /* random SV variants need this */
+#include <sys/select.h>
+#endif
 
 #ifdef HAVE_RANDOM		/* aficionados of ?rand48() should realize */
 #define SRAND srandom		/* that this doesn't need *strong* random */
@@ -235,7 +238,7 @@
 {
   errno = 0;
   if (o_verbose > 1)		/* normally we don't care */
-    bail (wrote_txt, wrote_net, wrote_out);
+    bail (wrote_txt, (char*) wrote_net, (char *) wrote_out);
   bail (" punt!");
 }
 
@@ -277,7 +280,7 @@
   if (p != NULL)
     memset (p, 0, s);
   else
-    bail ("Hmalloc %d failed", s);
+    bail ("Hmalloc %d failed", (char *) s);
   return (p);
 } /* Hmalloc */
 
@@ -465,7 +468,7 @@
     if (servent) {
       y = ntohs (servent->s_port);
       if (x != y)			/* "never happen" */
-	holler ("Warning: port-bynum mismatch, %d != %d", x, y);
+	holler ("Warning: port-bynum mismatch, %d != %d", (char *) x, (char *) y);
       strncpy (portpoop->name, servent->s_name, sizeof (portpoop->name));
     } /* if servent */
     goto gp_finish;
@@ -565,7 +568,7 @@
   if (! block)
     bail ("loadports: no block?!");
   if ((! lo) || (! hi))
-    bail ("loadports: bogus values %d, %d", lo, hi);
+    bail ("loadports: bogus values %d, %d", (char *) lo, (char *) hi);
   x = hi;
   while (lo <= x) {
     block[x] = 1;
@@ -671,7 +674,7 @@
       if (errno != EADDRINUSE)
 	break;
       else {
-	holler ("retrying local %s:%d", inet_ntoa (lclend->sin_addr), lp);
+	holler ("retrying local %s:%d", inet_ntoa (lclend->sin_addr), (char *) lp);
 	sleep (2);
 	errno = 0;			/* clear from sleep */
       } /* if EADDRINUSE */
@@ -679,7 +682,7 @@
   } /* if lad or lp */
   if (rr)
     bail ("Can't grab %s:%d with bind",
-	inet_ntoa(lclend->sin_addr), lp);
+	inet_ntoa(lclend->sin_addr), (char *) lp);
 
   if (o_listen)
     return (nnetfd);			/* thanks, that's all for today */
@@ -824,7 +827,7 @@
       strcat (bigbuf_net, "any");
     strcat (bigbuf_net, "] %d ...");
     z = ntohs (lclend->sin_port);
-    holler (bigbuf_net, z);
+    holler (bigbuf_net, (char *) z);
   } /* verbose -- whew!! */
 
 /* UDP is a speeeeecial case -- we have to do I/O *and* get the calling
@@ -936,9 +939,9 @@
       x = 1;
   if (x)					/* guilty! */
     bail ("invalid connection to [%s] from %s [%s] %d",
-	cp, whozis->name, whozis->addrs[0], z);
+	cp, whozis->name, whozis->addrs[0], (char *) z);
   holler ("connect to [%s] from %s [%s] %d",		/* oh, you're okay.. */
-	cp, whozis->name, whozis->addrs[0], z);
+	cp, whozis->name, whozis->addrs[0], (char *) z);
   return (nnetfd);				/* open! */
 
 dol_tmo:
@@ -966,7 +969,7 @@
 
   rr = write (fd, bigbuf_in, 1);
   if (rr != 1)
-    holler ("udptest first write failed?! errno %d", errno);
+    holler ("udptest first write failed?! errno %d", (char *) errno);
   if (o_wait)
     sleep (o_wait);
   else {
@@ -1143,7 +1146,7 @@
 /* if you don't have all this FD_* macro hair in sys/types.h, you'll have to
    either find it or do your own bit-bashing: *ding1 |= (1 << fd), etc... */
   if (fd > FD_SETSIZE) {
-    holler ("Preposterous fd value %d", fd);
+    holler ("Preposterous fd value %d", (char *) fd);
     return (1);
   }
   FD_SET (fd, ding1);		/* global: the net is open */
@@ -1251,7 +1254,7 @@
 
 /* sanity check.  Works because they're both unsigned... */
     if ((rzleft > 8200) || (rnleft > 8200)) {
-	holler ("Bogus buffers: %d, %d", rzleft, rnleft);
+	holler ("Bogus buffers: %d, %d", (char *) rzleft, (char *) rnleft);
 	rzleft = rnleft = 0;
     }
 /* net write retries sometimes happen on UDP connections */
@@ -1435,7 +1438,7 @@
 	if ((x) && (x == (x & 0x1c)))	/* mask off bits of fukt values */
 	  gatesptr = x;
 	else
-	  bail ("invalid hop pointer %d, must be multiple of 4 <= 28", x);
+	  bail ("invalid hop pointer %d, must be multiple of 4 <= 28", (char *) x);
 	break;
       case 'g':				/* srcroute hop[s] */
 	if (gatesidx > 8)
@@ -1565,7 +1568,7 @@
 #endif /* GAPING_SECURITY_HOLE */
       x = readwrite (netfd);		/* it even works with UDP! */
       if (o_verbose > 1)		/* normally we don't care */
-	holler (wrote_txt, wrote_net, wrote_out);
+	holler (wrote_txt, (char *) wrote_net, (char *) wrote_out);
       exit (x);				/* "pack out yer trash" */
     } else /* if no netfd */
       bail ("no connection");
@@ -1624,7 +1627,7 @@
       if (netfd > 0) {			/* Yow, are we OPEN YET?! */
 	x = 0;				/* pre-exit status */
 	holler ("%s [%s] %d (%s) open",
-	  whereto->name, whereto->addrs[0], curport, portpoop->name);
+	  whereto->name, whereto->addrs[0], (char *) curport, portpoop->name);
 #ifdef GAPING_SECURITY_HOLE
 	if (pr00gie)			/* exec is valid for outbound, too */
 	  doexec (netfd);
@@ -1637,7 +1640,7 @@
    Give it another -v if you want to see everything. */
 	if ((Single || (o_verbose > 1)) || (errno != ECONNREFUSED))
 	  holler ("%s [%s] %d (%s)",
-	    whereto->name, whereto->addrs[0], curport, portpoop->name);
+	    whereto->name, whereto->addrs[0], (char *) curport, portpoop->name);
       } /* if netfd */
       close (netfd);			/* just in case we didn't already */
       if (o_interval)
@@ -1652,7 +1655,7 @@
 
   errno = 0;
   if (o_verbose > 1)		/* normally we don't care */
-    holler (wrote_txt, wrote_net, wrote_out);
+    holler (wrote_txt, (char *) wrote_net, (char *) wrote_out);
   if (Single)
     exit (x);			/* give us status on one connection */
   exit (0);			/* otherwise, we're just done */
