--- sniffit.0.3.7.c.orig	2013-10-15 18:30:42.000000000 +1100
+++ sniffit.0.3.7.c	2013-10-15 18:33:29.000000000 +1100
@@ -1091,19 +1091,19 @@
   finish = check_packet (ipaddr, p_header, sp, filename, filename2, &info, header, SNIFMODE);
 
   if (finish == DROP_PACKET)
-    return;			/* Packet is broken */
+    return 0;			/* Packet is broken */
 
   if( (PROTOCOLS&F_IP)&&((PROTOCOLS&F_TCP)==0))
     memcpy (&iphead, (sp + PROTO_HEAD), sizeof (struct IP_header)),
       print_iphead (&iphead, 0);
 
   if (finish == DONT_EXAMINE)
-    return;			/* Packet is not for us */
+    return 0;			/* Packet is not for us */
 
   if(DUMPMODE==8)               /* Recording */
     {
     pcap_dump((unsigned char *) dev_dump, p_header, sp);
-    return;
+    return 0;
     }
 
   if((PROTOCOLS & F_IP)&&(PROTOCOLS & F_TCP)&&(finish<10))
@@ -1184,11 +1184,11 @@
 	  if (status == 0)
 	    {
 	      if (finish == TCP_FINISH)
-		return;
+		return 0;
 	      /* there was never data transmitted */
 	      /* seq_nr & datalen not important here yet */
 	      if ((dummy_pointer = add_dynam (filename, TCP, 1, 0, 0)) == NULL)
-		return;
+		return 0;
 	    }
 	  f = dummy_pointer->f;
 
@@ -1254,7 +1254,7 @@
 	  printf ("\nYou mixed incompatible options!\n");
 	  exit (1);
 	}
-      return;
+      return 0;
     }
 
   if ((finish < 10) && (LOGPARAM != 0))		/*  TCP packet - logfile   */
@@ -1334,7 +1334,7 @@
 	  break;
 	}
       printf ("\n");
-      return;
+      return 0;
     }
   if (finish < 30)		/* nothing yet */
     {
@@ -1367,7 +1367,7 @@
 	  printf ("\nImpossible error! Sniffer Hartattack!\n");
 	  exit (0);
 	}
-      return;
+      return 0;
     }
 }
 
@@ -1480,9 +1480,9 @@
 
   finish = check_mask (p_header, sp, conn_name, conn_name2, desc_string, &info);
   if (finish == DROP_PACKET)
-    return;			/* Packet is broken */
+    return 0;			/* Packet is broken */
   if (finish == DONT_EXAMINE)
-    return;			/* Packet is not for us */
+    return 0;			/* Packet is not for us */
 
   if (finish != TCP_FINISH)	/* finish: already logged, or to short to add */
     add_itemlist (running_connections, conn_name, desc_string);
