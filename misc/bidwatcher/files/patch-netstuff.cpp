--- netstuff.cpp.orig	Fri Jun 15 09:46:35 2001
+++ netstuff.cpp	Fri Mar 15 14:14:36 2002
@@ -22,6 +22,7 @@
 //
 
 #include <signal.h>
+#include "fix-hardcoding.h"
 
 bool cancelPressed;
 double avg_load_time = INITIAL_LOAD_TIME;
@@ -69,7 +70,12 @@
    soc_in.sin_port = htons(port);
 //   socketID = socket(2, SOCK_STREAM, 0);
    socketID = socket(AF_INET, SOCK_STREAM, 0);
-   if (socketID < 0) return 2;
+   if (socketID < 0) {
+#ifdef DEBUG_NETWORK
+	       fprintf( stderr, "rawFetchHtml: returning 2\n" );
+#endif
+	   return 2;
+   }
 
    set_nonblock(socketID);   
    err = ::connect(socketID, (struct sockaddr *)&soc_in, sizeof (soc_in));
@@ -90,6 +96,9 @@
 	       fprintf( stderr, "connection timed out\n" );
 #endif
 	       CloseSocket(socketID);
+#ifdef DEBUG_NETWORK
+	       fprintf( stderr, "rawFetchHtml: returning 4\n" );
+#endif
 	       return 4;
 	   }
        }
@@ -101,6 +110,9 @@
 		    err, errno, strerror( errno ) );
 #endif
 	   CloseSocket(socketID);
+#ifdef DEBUG_NETWORK
+	       fprintf( stderr, "rawFetchHtml: returning 2\n" );
+#endif
 	   return 2;
        }
    }
@@ -127,6 +139,9 @@
 		err, errno, strerror( errno ) );
 #endif
        CloseSocket(socketID);
+#ifdef DEBUG_NETWORK
+	       fprintf( stderr, "rawFetchHtml: returning 2\n" );
+#endif
        return 2;
    }
 
@@ -140,6 +155,9 @@
 		errno, strerror( errno ) );
 #endif
        CloseSocket(socketID);
+#ifdef DEBUG_NETWORK
+	       fprintf( stderr, "rawFetchHtml: returning 2\n" );
+#endif
        return 2;
    }
 
@@ -151,7 +169,14 @@
    time_since_pkt.start();
    while ( goodcall )
    {
-      if ( cancelPressed ) return 10;
+      if ( cancelPressed )
+      {
+#ifdef DEBUG_NETWORK
+	fprintf( stderr, "user cancelPressed, aborting FetchHtml\n." );
+	fprintf( stderr, "rawFetchHtml: returning 10\n" );
+#endif
+	  return 10;
+      }
       if ( counter == 5 )
       {
 	  counter = 0;
@@ -159,12 +184,18 @@
 	  if ( time_since_start.elapsed() > timeOut )
 	  {
 	      CloseSocket(socketID);
+#ifdef DEBUG_NETWORK
+	       fprintf( stderr, "rawFetchHtml: returning 4\n" );
+#endif
 	      return 4;
 	  }
 
 	  if ( time_since_pkt.elapsed() > timeOut/2 )
 	  {
 	      CloseSocket(socketID);
+#ifdef DEBUG_NETWORK
+	       fprintf( stderr, "rawFetchHtml: returning 4\n" );
+#endif
 	      return 4;
 	  }
       }
@@ -201,7 +232,16 @@
    // there is a slight chance that the web page was _exactly the
    // same size as the buffer, so we will  fix that:
    Buff[sizeOfBuff - 1] = '\0';
-   if ( !goodcall ) return 2; 
+   if ( !goodcall ) {
+#ifdef DEBUG_NETWORK
+	       fprintf( stderr, "rawFetchHtml: returning 2\n" );
+#endif
+   	return 2; 
+   }
+
+#ifdef DEBUG_NETWORK
+	       fprintf( stderr, "rawFetchHtml: returning 1\n" );
+#endif
    return 1; 
 } 
 
@@ -264,9 +304,9 @@
 
 	if( err != 1 || i != 0 )
 	{
-	    if( strncmp( WebPage, "/aw-cgi/eBayISAPI.dll?",
-			 sizeof( "/aw-cgi/eBayISAPI.dll?" ) - 1 ) == 0 )
-		page_start = WebPage + sizeof( "/aw-cgi/eBayISAPI.dll?" ) - 1;
+	    if( strncmp( WebPage, PATH_CGI_eBayISAPI,
+			 sizeof( PATH_CGI_eBayISAPI ) - 1 ) == 0 )
+		page_start = WebPage + sizeof( PATH_CGI_eBayISAPI ) - 1;
 	    else
 		page_start = WebPage;
 
@@ -296,6 +336,9 @@
 	default:
 	case 1:
 	case 10:
+#ifdef DEBUG_NETWORK
+	       fprintf( stderr, "FetchHtml: returning 1 or 10 - (%d)\n", err );
+#endif
 	    return err;
 	    break;
 
@@ -315,6 +358,9 @@
 	fprintf( stderr, "!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!--\n\n" );
 #endif
 
+#ifdef DEBUG_NETWORK
+	       fprintf( stderr, "FetchHtml: returning (%d)\n",err);
+#endif
     return err;
 }
 	    
