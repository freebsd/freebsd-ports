--- prober.c.orig	2012-01-25 04:33:22.000000000 +0800
+++ prober.c	2012-06-07 16:37:14.013216127 +0800
@@ -34,6 +34,8 @@
 #include <stdlib.h>
 #include <string.h>
 
+#include <sys/types.h>
+
 #define __FAVOR_BSD /* For compilation in Linux.  */
 #include <netinet/in.h>
 #include <netinet/udp.h>
@@ -357,27 +359,27 @@
   //following two lines for 802.11a/b/g/n links
   if(capacityup < 80000) capacityup = measupcap;
   if(capacitydown < 80000) capacitydown = measdowncap;
-  if(capacityup > 200000)
-  {
-	  printf("Upstream: greater than 200 Mbps.\n");
-	  capacityup = 195000;
-  }
-  else
-  {
+//  if(capacityup > 200000)
+//  {
+//	  printf("Upstream: greater than 200 Mbps.\n");
+//	  capacityup = 195000;
+//  }
+//  else
+//  {
 	  printf("Upstream: %d Kbps.\n", (int)capacityup);
 //	  capacityup *= 0.95; //reduce loss-based aborts
-  }
+//  }
   truecapup = capacityup;
-  if(capacitydown > 200000)
-  {
-	  printf("Downstream: greater than 200 Mbps.\n");
-	  capacitydown = 195000;
-  }
-  else
-  {
+//  if(capacitydown > 200000)
+//  {
+//	  printf("Downstream: greater than 200 Mbps.\n");
+//	  capacitydown = 195000;
+//  }
+//  else
+//  {
 	  printf("Downstream: %d Kbps.\n", (int)capacitydown);
 //	  capacitydown *= 0.95; //reduce loss-based aborts
-  }
+//  }
   truecapdown = capacitydown;
 
   printf("\nThe measurement will last for about %.1f minutes. Please wait.\n",
