--- popper/popper.c.orig	Fri Jun  1 23:24:14 2001
+++ popper/popper.c	Sun Mar 31 05:03:49 2002
@@ -125,8 +125,8 @@
     state_table     *   s;
     char                message [ MAXLINELEN ];
     pop_result          rslt = POP_FAILURE;
-    char            *   tgetline();
-    char            *   getline();
+    ssize_t		tgetline();
+    ssize_t		getline();
     
     /*
      * seed random with the current time to nearest second 
@@ -287,7 +287,7 @@
         if ( hangup ) {
             pop_exit ( &p, HANGUP );
         } 
-        else if ( tgetline ( message, MAXLINELEN, &p, pop_timeout ) == NULL ) {
+        else if ( tgetline ( message, MAXLINELEN, &p, pop_timeout ) < 0 ) {
             pop_exit ( &p, (poptimeout) ? TIMEOUT :  ABORT );
         } 
         else if ( StackSize ( &(p.InProcess) ) ) { 
@@ -400,8 +400,8 @@
  *  the input is discarded.
  */
 
-char
-*getline ( char *str, int size, POP *pPOP )
+ssize_t
+getline ( char *str, int size, POP *pPOP )
 {
     char *p       = NULL;
     char *pEnd    = NULL;
@@ -451,7 +451,7 @@
             }
             _DEBUG_LOG3 ( pPOP, "getline() returning %d: '%.*s'",
                           strlen(str), MIN(25, (int) strlen(str)), str );
-            return ( str );
+            return ( strlen(str) );
         } /* got a line */
 
         nRoom = pPOP->pcInBuf + nBufSz - pPOP->pcInEnd;
@@ -483,7 +483,22 @@
                 else
                     len = read ( pPOP->input_fd, junk, sizeof(junk) );
                 if ( len <= 0 )
-                    break;
+                {
+                   /*
+                    * patch by Isao SEKI <iseki@gongon.com> and
+                    * Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
+                    * return 0 is meaningless after buffer overflow
+                    */
+
+                   /* do not touch buffer before returning
+                    * since it seems that qpopper
+                    * believes in the contents of str
+                    */
+                                   
+                    pop_log (pPOP, POP_NOTICE, HERE,
+                           "read 0 byte. Possible buffer overflow\n");
+                    return (-1);
+                }
                 q = strchr ( junk, '\n' );
                 if ( q == NULL ) {
                     disc += len;
@@ -522,7 +537,7 @@
             } /* loop and discard until we see a '\n' */
 
             _DEBUG_LOG1 ( pPOP, "getline() returning %d", strlen(str) );
-            return ( str );
+            return ( strlen(str) );
         } /* nRoom == 0 */
 
         if ( pPOP->tls_started )
@@ -544,7 +559,7 @@
     } /* main loop */
 
     _DEBUG_LOG0 ( pPOP, "getline() returning NULL" );
-    return ( NULL );
+    return ( -1 );
 }
 
 
@@ -552,12 +567,12 @@
 /*
  * Get a line of input with a timeout.  This part does the timeout
  */
-char *
+ssize_t
 tgetline ( char *str, int size, POP *p, int timeout )
 {
     int ring();
-
-
+    ssize_t result;
+        
     (void) signal ( SIGALRM, VOIDSTAR ring );
     alarm ( timeout );
     if ( setjmp ( env ) ) {
@@ -565,12 +580,13 @@
         pop_log ( p, POP_NOTICE, HERE, "(v%s) Timeout (%d secs) during "
                                        "nw read from %s at %s (%s)",
                   VERSION, timeout, p->user, p->client, p->ipaddr );
+        result = 0;
     }
     else
-        str = getline ( str, size, p );
+        result = getline ( str, size, p );
     alarm  ( 0 );
     signal ( SIGALRM, SIG_DFL );
-    return ( str );
+    return ( result );
 }
 
 
