--- cv.c.orig	Tue Apr 18 15:54:34 2006
+++ cv.c	Sun Apr 30 18:20:44 2006
@@ -81,6 +81,7 @@
 
 		case CONVTYPE_DECTOHEX:
 			{
+				#define atoll(a) strtoll((a), (char **)NULL, 10)
 				long long int result = atoll(what);
 				char result_str[128];
 
