--- src/otfopen.c	22 Sep 2010 03:46:17 -0000	1.62
+++ src/otfopen.c	11 Feb 2011 02:55:05 -0000	1.63
@@ -2336,8 +2336,9 @@
     }
   for (i = 0; i < array->Count; i++)
     for (j = 0; j < ClassCount; j++)
-      if (read_anchor (otf, stream, offset + array->offset,
-		       &array->AnchorRecord[i].Anchor[j]) < 0)
+      if (array->AnchorRecord[i].Anchor[j].offset > 0
+	  && read_anchor (otf, stream, offset + array->offset,
+			  &array->AnchorRecord[i].Anchor[j]) < 0)
 	return -1;
   RESTORE_STREAM (stream, state);
   return 0;
@@ -2437,7 +2438,7 @@
 		      unsigned ClassCount, OTF_LigatureAttach *attach)
 {
   char *errfmt = "LigatureAttach%s";
-  int errret = 1;
+  int errret = -1;
   int i, j;
 
   SEEK_STREAM (stream, offset + attach->offset);
@@ -2483,8 +2484,10 @@
   for (i = 0; i < array->LigatureCount; i++)
     READ_OFFSET (stream, array->LigatureAttach[i].offset);
   for (i = 0; i < array->LigatureCount; i++)
-    read_ligature_attach (otf, stream, offset + array->offset,
-			  class_count, array->LigatureAttach + i);
+    if (array->LigatureAttach[i].offset > 0
+	&& read_ligature_attach (otf, stream, offset + array->offset,
+				 class_count, array->LigatureAttach + i) < 0)
+      return -1;
   RESTORE_STREAM (stream, state);
   return 0;
 }
@@ -2625,7 +2628,7 @@
 	  read_coverage (otf, stream, offset, &subtable->Coverage);
 	  read_coverage (otf, stream, offset,
 			 &subtable->u.mark_mark1.Mark2Coverage);
-	  READ_UINT16 (stream, subtable->u.mark_base1.ClassCount);
+	  READ_UINT16 (stream, subtable->u.mark_mark1.ClassCount);
 	  read_mark_array (otf, stream, offset,
 			   &subtable->u.mark_mark1.Mark1Array);
 	  read_anchor_array (otf, stream, offset,
