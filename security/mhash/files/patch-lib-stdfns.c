diff -urN -x .svn ../../branches/mhash-dist/lib/stdfns.c ./lib/stdfns.c
--- ../../branches/mhash-dist/lib/stdfns.c	2008-01-16 02:34:17.000000000 +0200
+++ ./lib/stdfns.c	2008-01-16 02:35:49.000000000 +0200
@@ -332,11 +332,11 @@
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
@@ -463,11 +463,11 @@
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
@@ -486,11 +486,11 @@
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
@@ -524,6 +524,8 @@
 	mutils_word8 *ptrOut = buffer;
 	mutils_word32 loop;
 
+	if (buffer == NULL)
+		return(NULL);
 	for (loop = 0; loop < len; loop++, ptrIn++)
 	{
 		*ptrOut++ = mutils_val2char((*ptrIn & 0xf0) >> 4);
