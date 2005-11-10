--- ./aslookup.c.orig	Wed Apr  5 05:35:56 2000
+++ ./aslookup.c	Wed Nov  9 22:53:13 2005
@@ -249,7 +249,7 @@
 			break;
 		case 'C':
 #ifdef DEBUG
-			printf("Compleate\n");
+			printf("Complete\n");
 #endif
 			stop = 1;
 			break;
@@ -936,7 +936,7 @@
 
 		if (strncmp(&line[3], "       ", 7) == 0) {
 #ifdef DEBUG
-			printf("Old Data Concatinate\n");
+			printf("Old Data Concatenate\n");
 #endif
 			bzero(buf,40);
 			strncpy(buf, pathcache.data, 3);
@@ -952,7 +952,7 @@
 			printf("%s:\n",pathcache.data);
 			searchas(pathcache.pathstr);
 		} else {
-			printf("%s: Dplicated AS Path\n",pathcache.data);
+			printf("%s: Duplicated AS Path\n",pathcache.data);
 		}
 	}
 	freecache();
@@ -987,7 +987,7 @@
 
                 if (strncmp(&line[3], "       ", 7) == 0) {
 #ifdef DEBUG
-                        printf("Old Data Concatinate: %s\n",olddata);
+                        printf("Old Data Concatenate: %s\n",olddata);
 #endif
                         if (strlen(olddata) > 0) {
                                 bzero(buf,40);
@@ -1007,7 +1007,7 @@
                         printf("%s:\n",pathcache.data);
                         searchas(pathcache.pathstr);
                 } else {
-                        printf("%s: Dplicated AS Path\n",pathcache.data);
+                        printf("%s: Duplicated AS Path\n",pathcache.data);
                 }
 	}
 	fclose(fp);
@@ -1034,7 +1034,7 @@
 	if (a == 0) {
 		hp = gethostbyname(hn);
 		if (hp == NULL) {
-			printf("Could not resolv : %s\n",hn);
+			printf("Could not resolve : %s\n",hn);
 			return(1);
 		}
 		bzero(&sin, sizeof(struct sockaddr_in));
