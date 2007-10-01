--- net_names.c.orig	2004-08-14 14:32:15.000000000 +0200
+++ net_names.c	2007-10-02 00:07:03.000000000 +0200
@@ -161,6 +161,9 @@
     return NULL;
 }
 
+static char *inet6_ntoa(uint32_t *addr);  /* should be replaced by addr2ascii */
+				    
+
 char *net_getname(long type, long *id)
 {
     char *buf, *name;
@@ -261,8 +264,6 @@
     case TTTTYPE_IPV6HOST:
     {
 	u_int32_t tmp[4];
-	static char *inet6_ntoa(u_int32_t *addr);  /* should be replaced
-						      by addr2ascii */
 	if ((buf = malloc(sizeof("xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:xxxx")))
 	    == NULL)
 	    fatal_error("get_protoname: no memory\n");
