--- MUTE/layers/pointToPoint/pointToPointCommunicator.cpp.orig	Sun Dec 21 00:02:08 2003
+++ MUTE/layers/pointToPoint/pointToPointCommunicator.cpp	Sun Dec 21 00:32:22 2003
@@ -1153,7 +1153,7 @@
 
 // handler to receive all messages from the routing layer
 // extra argument not used
-void mute_internalLowLevelMessageHandler( char *inFromAddress,
+int mute_internalLowLevelMessageHandler( char *inFromAddress,
                                           char *inToAddress,
                                           char *inBody,
                                           void *inExtraArgument ) {
@@ -1544,6 +1544,7 @@
         delete [] *( tokens->getElement( i ) );
         }
     delete tokens;
+    return (0);
     }
 
 
