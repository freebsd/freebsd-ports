--- MUTE/layers/messageRouting/test/testMessageRouter.cpp.orig	Sat Jan 24 18:30:19 2004
+++ MUTE/layers/messageRouting/test/testMessageRouter.cpp	Sat Jan 24 18:32:02 2004
@@ -21,12 +21,13 @@
 #include <stdio.h>
 
 
-void messageHandler( char *inFromAddress, char *inToAddress, char *inBody,
+int messageHandler( char *inFromAddress, char *inToAddress, char *inBody,
                      void *inExtraArgument ) {
     
     printf( "Got message from %s to %s:\n%s\n", inFromAddress,
             inToAddress, inBody );
 
+    return (0);
     }
 
 
