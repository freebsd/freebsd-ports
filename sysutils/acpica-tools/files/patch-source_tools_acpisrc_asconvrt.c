--- source/tools/acpisrc/asconvrt.c.orig	2022-10-20 21:13:02 UTC
+++ source/tools/acpisrc/asconvrt.c
@@ -1230,7 +1230,6 @@ AsTabify8 (
     char                    *NewSubBuffer;
     char                    *CommentEnd = NULL;
     UINT32                  SpaceCount = 0;
-    UINT32                  Column = 0;
     UINT32                  TabCount = 0;
     UINT32                  LastLineTabCount = 0;
     UINT32                  LastLineColumnStart = 0;
@@ -1246,7 +1245,6 @@ AsTabify8 (
             /* This is a standalone blank line */
 
             FirstNonBlank = NULL;
-            Column = 0;
             SpaceCount = 0;
             TabCount = 0;
             SubBuffer++;
@@ -1285,8 +1283,6 @@ AsTabify8 (
             }
         }
 
-        Column++;
-
         /* Check if we are in a comment */
 
         if ((SubBuffer[0] == '*') &&
@@ -1379,7 +1375,6 @@ AsTabify8 (
 
             FirstNonBlank = NULL;
             LastLineColumnStart = ThisColumnStart;
-            Column = 0;
             SpaceCount = 0;
         }
         else
