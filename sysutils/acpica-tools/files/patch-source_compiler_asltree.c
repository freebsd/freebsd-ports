--- source/compiler/asltree.c.orig	2017-03-03 17:25:50 UTC
+++ source/compiler/asltree.c
@@ -295,17 +295,14 @@ TrAllocateNode (
         }
 
         Gbl_CommentState.Latest_Parse_Node = Op;
-        if (Gbl_CommentState.Latest_Parse_Node->Asl.ParseOpName)
-        {
-            CvDbgPrint ("trallocatenode=Set latest parse node to this node.\n");
-            CvDbgPrint ("           Op->Asl.ParseOpName = %s\n",
-                Gbl_CommentState.Latest_Parse_Node->Asl.ParseOpName);
-            CvDbgPrint ("           Op->Asl.ParseOpcode = 0x%x\n", ParseOpcode);
+        CvDbgPrint ("trallocatenode=Set latest parse node to this node.\n");
+        CvDbgPrint ("           Op->Asl.ParseOpName = %s\n",
+            Gbl_CommentState.Latest_Parse_Node->Asl.ParseOpName);
+        CvDbgPrint ("           Op->Asl.ParseOpcode = 0x%x\n", ParseOpcode);
 
-            if (Op->Asl.FileChanged)
-            {
-                CvDbgPrint("    file has been changed!\n");
-            }
+        if (Op->Asl.FileChanged)
+        {
+            CvDbgPrint("    file has been changed!\n");
         }
 
         /*
