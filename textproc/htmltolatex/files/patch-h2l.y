
$FreeBSD$

--- h2l.y.orig	Wed Oct 10 14:24:26 2001
+++ h2l.y	Fri Feb 21 03:11:01 2003
@@ -1,4 +1,5 @@
 %{
+using namespace std;
 
 #include <iostream>
 #include <stdio.h>
@@ -136,6 +137,7 @@
 	;
 
 head_block_init:	TAG_HEAD_START	{ if (!gMainDataStart) InitiateMainData(); }
+	       ;
 head_block_start:	head_block_init TAG_CLOSE				{ gIgnoreNonTagChars = true; }
 	|				head_block_init  attribute_list TAG_CLOSE	{ gIgnoreNonTagChars = true; }
 	;
