--- ./ffget.c.orig	2008-12-13 03:13:09.000000000 +0200
+++ ./ffget.c	2012-12-01 00:41:29.000000000 +0200
@@ -550,7 +550,7 @@
 				// if we have another \r after it, in which case, we
 				// turn on SINGLE_DELIMETER_MODE.
 
-				if ( (*crlfpos == '\r') )
+				if (*crlfpos == '\r')
 				{
 					f->linebreak = FFGET_LINEBREAK_CR;
 					snprintf(f->lastbreak,sizeof(f->lastbreak),"\r");
