--- autorespond.c	Thu Feb  7 12:07:44 2002
+++ autorespond.c	Thu Feb  7 12:07:59 2002
@@ -377,6 +377,7 @@
 /*********************************************************
 ** find string in string - ignore case **/
 
+#ifdef NEED_STRCASESTR
 char *strcasestr( char *_s1, char *_s2 )
 {
 	char *s1;
@@ -399,7 +400,7 @@
 	else
 		return _s1 + (ptr - s1);
 }
-
+#endif
 
 
 
