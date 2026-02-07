--- tcp.c.orig	2007-11-09 20:01:31.000000000 +0100
+++ tcp.c	2007-11-09 20:02:17.000000000 +0100
@@ -204,8 +204,8 @@
 				fprintf(stderr,"Out of memory!\n");
 				return FALSE;
 			}
-			sprintf(data,"0x%s",arg);
-			len = compact_string(data);
+			sprintf((char *)data,"0x%s",arg);
+			len = compact_string((char *)data);
 			if(len==1)
 				addoption(*data,1,NULL,pack);
 			else
@@ -230,7 +230,7 @@
 			addoption(4,2,NULL,pack);
 		} else if (!strcmp(opt+2, "sack")) {
 		   /* Selective Acknowledge rfc1323 */
-			unsigned char *next;
+			char *next;
 			u_int32_t le, re;
 			u_int8_t *comb, *c;
 			int count=0;
