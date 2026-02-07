--- libI77/lread.c.orig	1999-11-09 14:58:44 UTC
+++ libI77/lread.c
@@ -369,7 +369,7 @@ l_CHAR(Void)
 			*p++ = ch;
 			f__lcount = 10*f__lcount + ch - '0';
 			if (++i == size) {
-				f__lchar = (char *)realloc(f__lchar,
+				f__lchar = (char *)reallocf(f__lchar,
 					(unsigned int)(size += BUFSIZE));
 				p = f__lchar + i;
 				}
@@ -401,7 +401,7 @@ l_CHAR(Void)
  noquote:
 			*p++ = ch;
 			if (++i == size) {
-				f__lchar = (char *)realloc(f__lchar,
+				f__lchar = (char *)reallocf(f__lchar,
 					(unsigned int)(size += BUFSIZE));
 				p = f__lchar + i;
 				}
@@ -414,7 +414,7 @@ l_CHAR(Void)
 		if(i==size)
 		{
 		newone:
-			f__lchar= (char *)realloc(f__lchar,
+			f__lchar= (char *)reallocf(f__lchar,
 					(unsigned int)(size += BUFSIZE));
 			p=f__lchar+i-1;
 			*p++ = ch;
