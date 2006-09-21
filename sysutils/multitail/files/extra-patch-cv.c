--- cv.c.orig	Fri Sep  8 08:38:28 2006
+++ cv.c	Thu Sep 21 21:09:36 2006
@@ -105,6 +105,7 @@
 
 		case CONVTYPE_EPOCHTODATE:
 			{
+				#define atoll(a) strtoll((a), (char **)NULL, 10)
 				char *new_str = epoch_to_str((time_t)atoll(what));
 
 				if (new_str)
@@ -131,6 +132,7 @@
 
 		case CONVTYPE_DECTOHEX:
 			{
+				#define atoll(a) strtoll((a), (char **)NULL, 10)
 				long long int result = atoll(what);
 				char result_str[128];
 
