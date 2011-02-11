--- example/otfdump.c	19 Mar 2010 12:27:02 -0000	1.27
+++ example/otfdump.c	11 Feb 2011 02:52:37 -0000	1.28
@@ -32,12 +32,8 @@
 
 #include <otf.h>
 
-char *indent_spaces[] =
-  { "", "  ", "    ", "      ", "        ", "          ", "            ",
-    "              ",  "                ",  "                  " };
-
 /* Indented print.  */
-#define IPRINT printf("\n%s", indent_spaces[indent]), printf
+#define IPRINT printf("\n%*s", indent * 2, ""), printf
 
 static void
 dump_tag (OTF_Tag tag)
@@ -457,6 +453,8 @@
 static void
 dump_anchor (int indent, OTF_Anchor *anchor)
 {
+  if (anchor->offset == 0)
+    return;
   IPRINT ("(Anchor (offset #x%04X) (AnchorFormat %d)",
 	  anchor->offset, anchor->AnchorFormat);
   indent++;
