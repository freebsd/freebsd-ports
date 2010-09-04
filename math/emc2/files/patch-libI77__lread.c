--- ./libI77/lread.c.orig	2010-08-31 08:39:32.000000000 -0400
+++ ./libI77/lread.c	2010-08-31 08:40:19.000000000 -0400
@@ -369,7 +369,7 @@
 			*p++ = ch;
 			f__lcount = 10*f__lcount + ch - '0';
 			if (++i == size) {
-				f__lchar = (char *)realloc(f__lchar,
+				f__lchar = (char *)reallocf(f__lchar,
 					(unsigned int)(size += BUFSIZE));
 				p = f__lchar + i;
 				}
@@ -401,7 +401,7 @@
  noquote:
 			*p++ = ch;
 			if (++i == size) {
-				f__lchar = (char *)realloc(f__lchar,
+				f__lchar = (char *)reallocf(f__lchar,
 					(unsigned int)(size += BUFSIZE));
 				p = f__lchar + i;
 				}
@@ -414,7 +414,7 @@
 		if(i==size)
 		{
 		newone:
-			f__lchar= (char *)realloc(f__lchar,
+			f__lchar= (char *)reallocf(f__lchar,
 					(unsigned int)(size += BUFSIZE));
 			p=f__lchar+i-1;
 			*p++ = ch;
