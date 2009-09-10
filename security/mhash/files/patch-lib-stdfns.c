Description: Check a memory allocation and use the POSIX INT_* constants.
Author: Peter Pentchev <roam@FreeBSD.org>
Forwarded: http://sourceforge.net/mailarchive/message.php?msg_name=20090910102100.GA26539%40straylight.m.ringlet.net
Last-Update: 2009-09-10

--- lib/stdfns.c.orig
+++ lib/stdfns.c
@@ -360,11 +360,11 @@
 		{
 			return(0);
 		}
-		return(-MAXINT);
+		return(-INT_MAX);
 	}
 	if (s2 == NULL)
 	{
-		return(MAXINT);
+		return(INT_MAX);
 	}
 
 	return(memcmp(s1, s2, n));
@@ -491,11 +491,11 @@
 		{
 			return(0);
 		}
-		return(-MAXINT);
+		return(-INT_MAX);
 	}
 	if (src2 == NULL)
 	{
-		return(MAXINT);
+		return(INT_MAX);
 	}
 	return(strcmp((char *) src1, (char *) src2));
 }
@@ -514,11 +514,11 @@
 		{
 			return(0);
 		}
-		return(-MAXINT);
+		return(-INT_MAX);
 	}
 	if (src2 == NULL)
 	{
-		return(MAXINT);
+		return(INT_MAX);
 	}
 	return(strncmp((char *) src1, (char *) src2, n));
 }
@@ -552,6 +552,8 @@
 	mutils_word8 *ptrOut = buffer;
 	mutils_word32 loop;
 
+ 	if (buffer == NULL)
+ 		return(NULL);
 	for (loop = 0; loop < len; loop++, ptrIn++)
 	{
 		*ptrOut++ = mutils_val2char((*ptrIn & 0xf0) >> 4);
