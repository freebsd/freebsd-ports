diff -urN -x .svn ../../vendor/vpopmail/vpopmail.c ./vpopmail.c
--- ../../vendor/vpopmail/vpopmail.c	Wed Oct  4 13:19:16 2006
+++ ./vpopmail.c	Wed Oct  4 15:44:20 2006
@@ -560,6 +560,8 @@
                 if (entry.realdomain == NULL) continue;
 
                 /* remove trailing '-' from entry.domain */
+		if (entry.realdomain <= entry.domain + 2 ||
+		    *(entry.realdomain-2) != '-') continue;
                 *(entry.realdomain-2) = '\0';
 
                 if ((p = strtok (NULL, ":")) == NULL) continue;
@@ -1229,6 +1231,7 @@
     for(i=0;tmpbuf1[i]!=0;++i) {
       if (tmpbuf1[i]=='\n') {
         tmpbuf1[i]=0;
+	break;
       }
     }
 
@@ -1239,6 +1242,7 @@
       if( 0 == strcmp(tmpbuf1,aliases[i])) {
         doit=0;
 //        fprintf( stderr, "      ***  DELETE  ***\n");
+	break;
         }
       }    
     if( doit ) {
@@ -1381,7 +1385,7 @@
     execl(QMAILNEWU,"qmail-newu", NULL);
     exit(127);
   } else {
-    wait(&pid);
+    waitpid(pid,&pid,0);
   }
   return(0);
 }
@@ -1633,7 +1637,8 @@
 
   //  If users/assign - need to delete last character
   if( 1 == file_type ) {
-    domain[--i] = 0;
+    if (i > 0)
+      domain[--i] = 0;
   } else {
     domain[i] = 0;
   }
@@ -1679,9 +1684,7 @@
     i=i+2;
 
     //  Clean out the domain variable
-    for(j=0;j<MAX_BUFF;j++) {
-      domain[j] = 0;
-    }
+    memset(domain, 0, sizeof(domain));
 
     //  Get one last look at the array before assembling it
 //    for(j=0;j<i;j++) {
@@ -1738,9 +1741,7 @@
  int i, count=0;
  char cur_domain[MAX_BUFF];
 
- sortrec sortdata[2000];
-
-//  sortdata = malloc(  file_lines * sizeof( sortrec ));
+ sortrec *sortdata = NULL;
 
 //  fprintf( stderr, "\n***************************************\n" 
 //                   "sort_file: %s\n", filename );
@@ -1761,8 +1762,8 @@
 #ifdef FILE_LOCKING
     unlock_lock(fd3, 0, SEEK_SET, 0);
     close(fd3);
-    return(VA_COULD_NOT_UPDATE_FILE);
 #endif
+    return(VA_COULD_NOT_UPDATE_FILE);
   }
 
   snprintf(tmpbuf1, sizeof(tmpbuf1), "%s", filename);
@@ -1770,19 +1771,31 @@
     if ( (fs = fopen(tmpbuf1, "w+")) == NULL ) {
       fclose(fs1);
 #ifdef FILE_LOCKING
-      close(fd3);
       unlock_lock(fd3, 0, SEEK_SET, 0);
+      close(fd3);
 #endif
       return(VA_COULD_NOT_UPDATE_FILE);
     }
   }
 
+  sortdata = malloc(  file_lines * sizeof( sortrec ));
+  if (sortdata == NULL) {
+    fclose(fs);
+    fclose(fs1);
+#ifdef FILE_LOCKING
+    unlock_lock(fd3, 0, SEEK_SET, 0);
+    close(fd3);
+#endif
+    return(VA_MEMORY_ALLOC_ERR);
+  }
+
   while( fgets(tmpbuf1,sizeof(tmpbuf1),fs) != NULL ) {
 
     //  Trim \n off end of line.
     for(i=0;tmpbuf1[i]!=0;++i) {
       if (tmpbuf1[i]=='\n') {
         tmpbuf1[i]=0;
+	break;
       }
     }
 
@@ -1793,6 +1806,22 @@
 
 //    fprintf( stderr, "   Entry: %s\n", tmpbuf1 );
 
+    // A new entry; is the allocated memory enough?
+    if (count == file_lines) {
+      fclose(fs);
+      fclose(fs1);
+#ifdef FILE_LOCKING
+      unlock_lock(fd3, 0, SEEK_SET, 0);
+      close(fd3);
+#endif
+      for (i = 0; i < count; i++) {
+	free( sortdata[i].key );
+	free( sortdata[i].value );
+      }
+      free( sortdata );
+      return(VA_MEMORY_ALLOC_ERR);
+    }
+
     extract_domain( cur_domain, tmpbuf1, file_type );
 
     sortdata[count].key = strdup( cur_domain );
@@ -1826,7 +1855,11 @@
   close(fd3);
 #endif
 
-//  free( sortrec );
+  for (i = 0; i < count; i++) {
+    free( sortdata[i].key );
+    free( sortdata[i].value );
+  }
+  free( sortdata );
 
   return(0);
 }
@@ -1893,6 +1926,7 @@
     for(i=0;tmpbuf1[i]!=0;++i) {
       if (tmpbuf1[i]=='\n') {
         tmpbuf1[i]=0;
+	break;
       }
     }
 
@@ -2028,7 +2062,7 @@
     execl(QMAILNEWMRH,"qmail-newmrh", NULL);
     exit(127);
   } else {
-    wait(&pid);
+    waitpid(pid,&pid,0);
   }
   return(0);
 }
@@ -2406,7 +2440,7 @@
 
   while( fgets(tmpbuf,sizeof(tmpbuf),fs) != NULL ) {
     /* usually any newlines into nulls */
-    for(i=0;tmpbuf[i]!=0;++i) if (tmpbuf[i]=='\n') tmpbuf[i]=0;
+    for(i=0;tmpbuf[i]!=0;++i) if (tmpbuf[i]=='\n') { tmpbuf[i]=0; break; }
     /* Michael Bowe 14th August 2003
      * What happens if domain isnt null terminated?
      */
@@ -2899,12 +2933,12 @@
 
 int result;
 
-//  NOTE: vopen_smpt_relay returns <0 on error 0 on duplicate 1 added
+//  NOTE: vopen_smtp_relay returns <0 on error 0 on duplicate 1 added
 //  check for failure.
 
   /* store the user's ip address into the sql relay table */
   if (( result = vopen_smtp_relay()) < 0 ) {   //   database error
-      vsqlerror( stderr, "Error. vopen_smpt_relay failed" );
+      vsqlerror( stderr, "Error. vopen_smtp_relay failed" );
       return (verrori);
   } else if ( result == 1 ) {
     /* generate a new tcp.smtp.cdb file */
@@ -3198,7 +3232,7 @@
   close(tcprules_fdm);  
 
   /* wait untill tcprules finishes so we don't have zombies */
-  while(wait(&wstat)!= (int)pid);
+  waitpid(pid,&wstat,0);
 
   /* if tcprules encounters an error, then the tempfile will be
    * left behind on the disk. We dont want this because we could
