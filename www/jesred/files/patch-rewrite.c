--- rewrite.c.orig	Sat Aug 15 09:01:15 1998
+++ rewrite.c	Mon Jun  4 09:51:42 2007
@@ -60,7 +60,7 @@
     int c, i;
     struct in_addr address;
     char *token, *new_token;
-    char *end[4];
+    char *end[5];
     
     c = 0;
     token = strchr(buff,' ');
@@ -87,11 +87,17 @@
 		    *new_token = '\0';
 		    end[3] = new_token;
 		    *method = token;
+		    new_token = strchr(token,' ');
+		    if (new_token) {
+			c++;
+			*new_token = '\0';
+			end[4] = new_token;
+		    }
 		}
 	    }
 	}
     }
-    if(c != 4) {
+    if(c < 4) {
 	for(i = 0; i < c; i++) {
 	    if ( end[i] )
 		*end[i] = ' ';
@@ -104,16 +110,16 @@
 #endif    
     
     /* all methods must be GET or ICP_QUERY */
-    c = 0;
+    i = 0;
     if (allow_siblings && (! strcmp(*method, "ICP_QUERY")) )
-	    c--;
+	i--;
     if( strcmp(*method, "GET") )
-	c++;
-    if ( c ) {
+	i++;
+    if ( i ) {
 #ifdef DEBUG
-	for(c = 0; c < 4; c++) {
-	    if ( end[c] )
-		*end[c] = ' ';
+	for(i = 0; i < c; i++) {
+	    if ( end[i] )
+		*end[i] = ' ';
 	}
 	log(DEBG, "method not \"GET\" %s\n", buff);
 #endif	
