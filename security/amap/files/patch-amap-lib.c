--- amap-lib.c.orig	Wed Jun 29 17:23:56 2005
+++ amap-lib.c	Wed Jun 29 17:28:09 2005
@@ -125,10 +125,8 @@
   int len = strlen("http://");
   int wlen = strlen(webfile);
   int port = 80, s, result = 1, datalen = 0, version = -1;
-int xx = 0;
   unsigned long int ip;
   time_t epoch;
-  struct in_addr in;
   struct hostent *target;
   struct sockaddr_in addr;
   struct tm *the_time;
@@ -404,8 +402,8 @@
   char *ptr;
   char *only_trigger = NULL;
   int i;
-  int a;
-  int b;
+  int a = 0;
+  int b = 0;
   int count;
   int count_triggers = 0;
 
@@ -577,7 +575,7 @@
   char *proto;
   char *length;
   char *string;
-  char *ptr;
+  char *ptr = NULL;
   int errptr;
   int i;
   int count;
@@ -740,7 +738,7 @@
   char *portinfo;
   char *proto;
   char *ptr;
-  int ip_prot;
+  int ip_prot = 0;
   int count = 0;
 
   f = amap_open_file(filename, "nmap", "", opt->verbose);
@@ -1585,7 +1583,7 @@
   amap_struct_targets *target = (amap_struct_targets*) targets;
   amap_struct_ports *port;
   amap_struct_identifications *ids;
-  amap_struct_identifications *ids_save;
+  amap_struct_identifications *ids_save = NULL;
   amap_struct_coms coms[AMAP_MAX_TASKS];
   amap_struct_scaninfo scaninfo;
 //  struct sockaddr_in target_in;
@@ -1593,7 +1591,7 @@
   char *rpc_ptr = NULL;
   int todo = 0;
   int ready_for_next;
-  int i;
+  int i = 0;
   int ii;
   int s;
   int ret;
