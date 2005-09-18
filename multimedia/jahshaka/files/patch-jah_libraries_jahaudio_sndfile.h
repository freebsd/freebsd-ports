--- jah/libraries/jahaudio/sndfile.h.orig
+++ jah/libraries/jahaudio/sndfile.h
@@ -233,7 +233,7 @@
 ** off64_t (Solaris), __int64_t (Win32) etc.
 */
 
-typedef loff_t	sf_count_t ;
+typedef off_t	sf_count_t ;
 
 #define SF_COUNT_MAX		0x7FFFFFFFFFFFFFFFLL
 
