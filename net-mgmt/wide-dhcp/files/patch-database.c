--- server/database.c.orig	Fri Jan  1 22:35:33 1999
+++ server/database.c	Sun Aug  3 19:55:32 2003
@@ -560,15 +560,15 @@
   char **cp;
   struct in_addr *subnet;
 {
-  char *tmpstr;
+  char *tmpstr, *line;
   struct in_addr *tmpaddr;
 
-  if ((tmpstr = get_string(cp)) == NULL) {
+  if ((line = get_string(cp)) == NULL) {
     errno = 0;
     syslog(LOG_WARNING, "Can't get strings");
     return(-1);
   }
-
+  tmpstr = line;
   if ((tmpaddr = get_ip(&tmpstr)) == NULL) {
     errno = 0;
     syslog(LOG_WARNING, "get_ip() error in read_subnet()");
@@ -576,7 +576,7 @@
   }
 
   *subnet = *tmpaddr;
-  free(tmpstr);
+  free(line);
   free(tmpaddr);
 
   return(0);
