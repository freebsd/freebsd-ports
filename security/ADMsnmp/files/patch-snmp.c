--- snmp.c.orig	Wed Feb 17 07:20:05 1999
+++ snmp.c	Sun Apr  6 16:31:38 2003
@@ -33,6 +33,8 @@
 #include <sys/stat.h>
 #include <netdb.h>
 #include <netinet/in.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 
 
 struct snmpchex
@@ -231,7 +233,7 @@
 		   /** get the ID **/
 		    sn->id = buf[i + 2];
 		    for (i = i + (buf[i + 1] + 2); i < size && i + 2 < size; i++)
-		      if (buf[i] == '\x02')
+		      if (buf[i] == '\x02') {
 			if (buf[i + 1] == '\x01')
 			  {
 			    /** return code **/
@@ -241,6 +243,7 @@
 			  }
 			else
 			  return (-1);
+			}
 		  }
 	    }
       }
@@ -300,7 +303,7 @@
   memset (buf, 0, sizeofbuf);
   i = getreq (buf, namez, GETREQ_SYSDEC, id, set_req);
   memcpy ((buf + i), sysdec, GETREQ_SYSDEC);
-  return (sendto (sock, buf, i + GETREQ_SYSDEC, 0, sin, sizeof (struct sockaddr_in)));
+  return (sendto (sock, buf, i + GETREQ_SYSDEC, 0, (const struct sockaddr *)sin, sizeof (struct sockaddr_in)));
 }
 
 /** getreq paket **/
@@ -460,7 +463,7 @@
       i = 0;
       /** we get an answer !!!! */
       
-      if ((i = recvfrom (sock, (char *) &buf, sizeof (buf), 0, &sin, &x)) > 0)
+      if ((i = recvfrom (sock, (char *) &buf, sizeof (buf), 0, (struct sockaddr *) &sin, &x)) > 0)
 	{
 	  nd = 0;
 	 /** extract the ID the return code and the community name **/
@@ -544,7 +547,7 @@
      "[-waitfor] <mili>  : time in milisecond in each send of snmprequest\n"
 	  "[-sleep]   <second> : time in second of the scan process life\n"
 	  "[-manysend] <number>: how many paket to send by request \n"
-     "[-inter] <mili>     : time to wait in milisecond after each request");
+     "[-inter] <mili>     : time to wait in milisecond after each request\n");
 }
 
 int
@@ -581,7 +584,7 @@
       printf ("cant resolve hostname!\n");
       exit (-1);
     }
-  opz.wordfile = strdup ("snmp.passwd");
+  opz.wordfile = strdup ("PORTSHAREDIR/snmp.passwd");
   opz.outputfile = NULL;
   opz.guess = -1;
   opz.manysend = 2;
