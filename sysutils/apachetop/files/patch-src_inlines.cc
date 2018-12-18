--- src/inlines.cc.orig	2018-08-28 11:21:23 UTC
+++ src/inlines.cc
@@ -4,10 +4,10 @@
 #define ONE_EIGHTH      4
 #define HIGH_BITS       (~((unsigned int)(~0) >> ONE_EIGHTH))
 
-inline unsigned int StringHash(register const char *str)
+inline unsigned int StringHash( const char *str)
 {
-	register unsigned int val;
-	register unsigned int i;
+	 unsigned int val;
+	 unsigned int i;
 
 	for (val = 0; *str; str++)
 	{
@@ -19,9 +19,9 @@ inline unsigned int StringHash(register const char *st
 	return val;
 }
 
-inline unsigned int QuickHash(register const char *str)
+inline unsigned int QuickHash( const char *str)
 {
-	register unsigned int val, tmp;
+	 unsigned int val, tmp;
 
 	for(val = 0 ; *str ; str++)
 	{
@@ -32,7 +32,7 @@ inline unsigned int QuickHash(register const char *str
 	return val;
 }
 
-inline unsigned long TTHash(register const char *str)
+inline unsigned long TTHash( const char *str)
 {
 	unsigned long hash = 5381;
 	int c;
