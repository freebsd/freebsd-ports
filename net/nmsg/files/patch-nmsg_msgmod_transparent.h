--- nmsg/msgmod/transparent.h.orig	2013-11-26 14:22:39.000000000 -0800
+++ nmsg/msgmod/transparent.h	2014-07-26 13:46:17.000000000 -0700
@@ -96,7 +96,7 @@
     case PROTOBUF_C_TYPE_BYTES:
       return sizeof (ProtobufCBinaryData);
     }
-  PROTOBUF_C_ASSERT_NOT_REACHED ();
+  assert(0);
   return 0;
 }
 
