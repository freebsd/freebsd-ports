--- scsilib/inc/getfp.c.orig	2003-07-12 23:10:47 UTC
+++ scsilib/inc/getfp.c
@@ -56,7 +56,7 @@
 
 EXPORT	void	**___fpoff	__PR((char *cp));
 
-EXPORT void **
+EXPORT __noinline void **
 getfp()
 {
 		long	**dummy[1];
@@ -73,7 +73,7 @@ getfp()
  * We need this function to fool GCCs check for returning addresses
  * from outside the functions local address space.
  */
-EXPORT void **
+EXPORT __noinline void **
 ___fpoff(cp)
 	char	*cp;
 {
