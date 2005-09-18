--- jah/libraries/jahaudio/alaw.c.orig
+++ jah/libraries/jahaudio/alaw.c
@@ -521,9 +521,9 @@
 {	while (count)
 	{	count -- ;
 		if (ptr [count] >= 0)
-			buffer [count] = alaw_encode [(lrintf (normfact * ptr [count])) / 16] ;
+			buffer [count] = alaw_encode [(int)((lrintf (normfact * ptr [count])) / 16)] ;
 		else
-			buffer [count] = 0x7F & alaw_encode [(lrintf (normfact * ptr [count])) / -16] ;
+			buffer [count] = 0x7F & alaw_encode [(int)((lrintf (normfact * ptr [count])) / -16)] ;
 		} ;
 } /* f2alaw_array */
 
@@ -532,9 +532,9 @@
 {	while (count)
 	{	count -- ;
 		if (ptr [count] >= 0)
-			buffer [count] = alaw_encode [(lrint (normfact * ptr [count])) / 16] ;
+			buffer [count] = alaw_encode [(int)((lrint (normfact * ptr [count])) / 16)] ;
 		else
-			buffer [count] = 0x7F & alaw_encode [(lrint (normfact * ptr [count])) / -16] ;
+			buffer [count] = 0x7F & alaw_encode [(int)((lrint (normfact * ptr [count])) / -16)] ;
 		} ;
 } /* d2alaw_array */
 
