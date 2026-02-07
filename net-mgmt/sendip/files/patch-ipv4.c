--- ipv4.c.orig	2007-11-09 20:01:39.000000000 +0100
+++ ipv4.c	2007-11-09 20:02:11.000000000 +0100
@@ -209,8 +209,8 @@
 				fprintf(stderr,"Out of memory!\n");
 				return FALSE;
 			}
-			sprintf(data,"0x%s",arg);
-			len = compact_string(data);
+			sprintf((char *)data,"0x%s",arg);
+			len = compact_string((char *)data);
 			cp=(*data&0x80)>>7;
 			cls=(*data&0x60)>>5;
 			num=(*data&0x1F);
@@ -237,7 +237,7 @@
 				free(data);
 				return FALSE;
 			} else {
-				addoption(0,0,7,len+2,data,pack);
+				addoption(0,0,7,len+2,(uint8_t *)data,pack);
 				free(data);
 			}
 		} else if(!strcmp(opt+2, "ts")) {
@@ -352,7 +352,7 @@
 				data_in = next;
 			}
 
-			addoption(0,2,4,data_out-data+2,data,pack);
+			addoption(0,2,4,data_out-data+2,(uint8_t *)data,pack);
 			free(data);
 			/* End of timestamp parsing */
 
@@ -377,7 +377,7 @@
 				free(data);
 				return FALSE;
 			} else {
-				addoption(1,0,3,len+2,data,pack);
+				addoption(1,0,3,len+2,(unsigned char *)data,pack);
 				free(data);
 			}
 		} else if(!strcmp(opt+2, "sid")) {
@@ -399,7 +399,7 @@
 				free(data);
 				return FALSE;
 			} else {
-				addoption(1,0,9,len+2,data,pack);
+				addoption(1,0,9,len+2,(uint8_t *)data,pack);
 				free(data);
 			}
 		} else {
