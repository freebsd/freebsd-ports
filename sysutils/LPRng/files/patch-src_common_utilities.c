--- src/common/utilities.c.orig
+++ src/common/utilities.c
@@ -600,22 +600,6 @@
 	return( n );
 }
 
-
-char *Brk_check_size( void )
-{
-	static char b[128];
-	static char* Top_of_mem;	/* top of allocated memory */
-	char *s = sbrk(0);
-	int   v = s - Top_of_mem;
-	if( Top_of_mem == 0 ){
-		plp_snprintf(b, sizeof(b), "BRK: initial value 0x%lx", Cast_ptr_to_long(s) );
-	} else {
-		plp_snprintf(b, sizeof(b), "BRK: new value 0x%lx, increment %d", Cast_ptr_to_long(s), v );
-	}
-	Top_of_mem = s;
-	return(b);
-}
-
 char *mystrncat( char *s1, const char *s2, int len )
 {
 	int size;
