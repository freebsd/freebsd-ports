--- h2l.y.orig	Sun Dec  1 22:57:58 2002
+++ h2l.y	Sun Dec  1 22:58:30 2002
@@ -136,6 +136,7 @@
 	;
 
 head_block_init:	TAG_HEAD_START	{ if (!gMainDataStart) InitiateMainData(); }
+	       ;
 head_block_start:	head_block_init TAG_CLOSE				{ gIgnoreNonTagChars = true; }
 	|				head_block_init  attribute_list TAG_CLOSE	{ gIgnoreNonTagChars = true; }
 	;
