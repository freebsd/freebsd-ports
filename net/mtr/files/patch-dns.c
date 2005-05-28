Index: dns.c
diff -u -p dns.c.orig dns.c
--- dns.c.orig	Tue Jan 11 17:32:42 2005
+++ dns.c	Thu Feb  3 19:25:28 2005
@@ -437,7 +437,7 @@ char *strlongip(ip_t * ip)
 }
 
 
-int longipstr(char *s, ip_t *dst)
+int longipstr(char *s, ip_t *dst, int af)
 {
 #ifdef ENABLE_IPV6
   return inet_pton( af, s, dst );
@@ -488,7 +488,7 @@ void dns_open(void)
 	    strerror(errno));
     exit(-1);
   }
-  longipstr( "127.0.0.1", &localhost );
+  longipstr( "127.0.0.1", &localhost, AF_INET );
   aseed = time(NULL) ^ (time(NULL) << 3) ^ (dword)getpid();
   for (i = 0;i < BashSize;i++) {
     idbash[i] = NULL;
@@ -1228,7 +1228,7 @@ void dns_ack(void)
 	if ( addrcmp( (void *) &(_res.nsaddr_list[i].sin_addr),
 		      (void *) &(from4->sin_addr), (int) AF_INET ) == 0 ||
 	     addrcmp( (void *) &(_res.nsaddr_list[i].sin_addr),
-		      (void *) &unspec_addr, (int) AF_INET ) != 0 )	/* 0.0.0.0 replies as 127.0.0.1 */
+		      (void *) &unspec_addr, (int) AF_INET ) == 0 )	/* 0.0.0.0 replies as 127.0.0.1 */
 	  break;
     } else
       for (i = 0;i < _res.nscount;i++)
