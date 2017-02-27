--- source/compiler/asltree.c.orig	2017-02-25 00:43:54 UTC
+++ source/compiler/asltree.c
@@ -187,7 +187,7 @@ TrAllocateNode (
         }
 
         Gbl_CommentState.Latest_Parse_Node = Op;
-        if (Gbl_CommentState.Latest_Parse_Node->Asl.ParseOpName)
+        if (Gbl_CommentState.Latest_Parse_Node->Asl.ParseOpName[0])
         {
             CvDbgPrint ("trallocatenode=Set latest parse node to this node.\n");
             CvDbgPrint ("           Op->Asl.ParseOpName = %s\n",
