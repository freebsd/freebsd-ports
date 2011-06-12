--- ./prober.c.orig	2009-11-29 00:47:46.000000000 -0800
+++ ./prober.c	2011-06-11 10:51:08.000000000 -0700
@@ -34,6 +34,8 @@
 #include <stdlib.h>
 #include <string.h>
 
+#include <sys/types.h>
+
 #define __FAVOR_BSD /* For compilation in Linux.  */
 #include <netinet/in.h>
 #include <netinet/udp.h>
@@ -356,27 +358,27 @@
   //XXX: the meas code needs trains and lower cpu
   if(capacityup < 80000) capacityup = measupcap;
   if(capacitydown < 80000) capacitydown = measdowncap;
-  if(capacityup > 100000)
+  /* if(capacityup > 100000)
   {
 	  printf("Upstream: greater than 100 Mbps.\n");
 	  capacityup = 95000;
   }
   else
-  {
+  { */
 	  printf("Upstream: %d Kbps.\n", (int)capacityup);
 //	  capacityup *= 0.95; //reduce loss-based aborts
-  }
+  /* } */
   truecapup = capacityup;
-  if(capacitydown > 100000)
+  /* if(capacitydown > 100000)
   {
 	  printf("Downstream: greater than 100 Mbps.\n");
 	  capacitydown = 95000;
   }
   else
-  {
+  { */
 	  printf("Downstream: %d Kbps.\n", (int)capacitydown);
 //	  capacitydown *= 0.95; //reduce loss-based aborts
-  }
+  /* } */
   truecapdown = capacitydown;
 
   printf("\nThe measurement will last for about %.1f minutes. Please wait.\n",
