--- dns.c      2006-03-22 19:45:58.000000000 -1000
+++ dns.c      2006-03-25 11:41:31.000000000 -1000
@@ -1357,7 +1357,7 @@
 #ifdef ENABLE_IPV6
 /* Returns an ip6.arpa character string. */
 void addr2ip6arpa( ip_t * ip, char * buf ) {
-  char * p = (char *) ip;
+  unsigned char * p = (unsigned char *) ip;
   char * b = buf;
   int i;
