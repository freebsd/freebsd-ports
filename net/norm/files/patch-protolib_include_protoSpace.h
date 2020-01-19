--- protolib/include/protoSpace.h.orig	2011-09-08 18:57:12 UTC
+++ protolib/include/protoSpace.h
@@ -89,7 +89,7 @@ class ProtoSpace
                 }
 #else               
                 ProtoTree::Endian GetEndian() const
-                        return ProtoTree::ENDIAN_BIG;
+                        {return ProtoTree::ENDIAN_BIG;}
                 void SetNode(Node* theNode)
                     {memcpy(key+sizeof(double), &theNode, sizeof(Node*));}
                 Node* GetNode() const
