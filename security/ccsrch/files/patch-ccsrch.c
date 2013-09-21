--- ccsrch.c.orig	2013-09-16 16:15:41.000000000 +0400
+++ ccsrch.c	2013-09-16 16:22:57.000000000 +0400
@@ -567,7 +567,7 @@
   int             vnum = 0;
 
   memset(&num2buf, '\0', 3);
-  snprintf(num2buf, 3, "%d%d\0", cardbuf[0], cardbuf[1]);
+  snprintf(num2buf, 3, "%d%d", cardbuf[0], cardbuf[1]);
   vnum = atoi(num2buf);
   if ((vnum > 50) && (vnum < 56))
     print_result("MASTERCARD", 16, offset);
@@ -580,7 +580,7 @@
   int             vnum = 0;
 
   memset(&num2buf, '\0', 2);
-  snprintf(num2buf, 2, "%d\0", cardbuf[0]);
+  snprintf(num2buf, 2, "%d", cardbuf[0]);
   vnum = atoi(num2buf);
   if (vnum == 4)
     print_result("VISA", 16, offset);
@@ -593,7 +593,7 @@
   int             vnum = 0;
 
   memset(&num2buf, '\0', 5);
-  snprintf(num2buf, 5, "%d%d%d%d\0", cardbuf[0], cardbuf[1], cardbuf[2], cardbuf[3]);
+  snprintf(num2buf, 5, "%d%d%d%d", cardbuf[0], cardbuf[1], cardbuf[2], cardbuf[3]);
   vnum = atoi(num2buf);
   if (vnum == 6011)
     print_result("DISCOVER", 16, offset);
@@ -605,8 +605,8 @@
   char            num2buf[5];
   int             vnum = 0;
 
-  memset(&num2buf, '\0', 2);
-  snprintf(num2buf, 5, "%d%d%d%d\0", cardbuf[0], cardbuf[1], cardbuf[2], cardbuf[3]);
+  memset(&num2buf, '\0', 5);
+  snprintf(num2buf, 5, "%d%d%d%d", cardbuf[0], cardbuf[1], cardbuf[2], cardbuf[3]);
   vnum = atoi(num2buf);
   if ((vnum == 3088) || (vnum == 3096) || (vnum == 3112) || (vnum == 3158) || (vnum == 3337) || (vnum == 3528) || (vnum == 3529))
     print_result("JCB", 16, offset);
@@ -619,7 +619,7 @@
   int             vnum = 0;
 
   memset(&num2buf, '\0', 3);
-  snprintf(num2buf, 3, "%d%d\0", cardbuf[0], cardbuf[1]);
+  snprintf(num2buf, 3, "%d%d", cardbuf[0], cardbuf[1]);
   vnum = atoi(num2buf);
   if ((vnum == 34) || (vnum == 37))
     print_result("AMEX", 15, offset);
@@ -632,7 +632,7 @@
   int             vnum = 0;
 
   memset(&num2buf, '\0', 5);
-  snprintf(num2buf, 5, "%d%d%d%d\0", cardbuf[0], cardbuf[1], cardbuf[2], cardbuf[3]);
+  snprintf(num2buf, 5, "%d%d%d%d", cardbuf[0], cardbuf[1], cardbuf[2], cardbuf[3]);
   vnum = atoi(num2buf);
   if ((vnum == 2014) || (vnum == 2149))
     print_result("ENROUTE", 15, offset);
@@ -645,7 +645,7 @@
   int             vnum = 0;
 
   memset(&num2buf, '\0', 5);
-  snprintf(num2buf, 5, "%d%d%d%d\0", cardbuf[0], cardbuf[1], cardbuf[2], cardbuf[3]);
+  snprintf(num2buf, 5, "%d%d%d%d", cardbuf[0], cardbuf[1], cardbuf[2], cardbuf[3]);
   vnum = atoi(num2buf);
   if ((vnum == 2131) || (vnum == 1800) || (vnum == 3528) || (vnum == 3529))
     print_result("JCB", 15, offset);
@@ -660,9 +660,9 @@
   int             vnum2 = 0;
 
   memset(&num2buf, '\0', 4);
-  memset(&num2buf2, '\0', 2);
-  snprintf(num2buf, 4, "%d%d%d\0", cardbuf[0], cardbuf[1], cardbuf[2]);
-  snprintf(num2buf2, 3, "%d%d\0", cardbuf[0], cardbuf[1]);
+  memset(&num2buf2, '\0', 3);
+  snprintf(num2buf, 4, "%d%d%d", cardbuf[0], cardbuf[1], cardbuf[2]);
+  snprintf(num2buf2, 3, "%d%d", cardbuf[0], cardbuf[1]);
   vnum = atoi(num2buf);
   vnum2 = atoi(num2buf2);
   if (((vnum > 299) && (vnum < 306)) || ((vnum > 379) && (vnum < 389)) || (vnum2 == 36))
@@ -690,9 +690,9 @@
   int end_time=0;
 
   end_time=time(NULL);
-  fprintf(stdout, "\n\nFiles searched ->\t\t%d\n", file_count);
+  fprintf(stdout, "\n\nFiles searched ->\t\t%ld\n", file_count);
   fprintf(stdout, "Search time (seconds) ->\t%d\n", ((int)time(NULL) - init_time));
-  fprintf(stdout, "Credit card matches->\t\t%d\n", total_count);
+  fprintf(stdout, "Credit card matches->\t\t%ld\n", total_count);
   if (tracksrch)
     fprintf(stdout, "Track data pattern matches->\t%d\n\n", trackdatacount);
   fprintf(stdout, "\nLocal end time: %s\n\n", ctime((time_t *)&end_time));
