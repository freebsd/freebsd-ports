diff -urN -x .svn ../../branches/vendor/mhash/lib/sha1.c ./lib/sha1.c
--- ../../branches/vendor/mhash/lib/sha1.c	2008-01-16 14:26:51.000000000 +0200
+++ ./lib/sha1.c	2008-01-16 15:00:01.000000000 +0200
@@ -59,10 +59,10 @@
    save one boolean operation each - thanks to Rich Schroeppel,
    rcs@cs.arizona.edu for discovering this */
 
-#define f1(x,y,z)   ( z ^ ( x & ( y ^ z ) ) )           /* Rounds  0-19 */
-#define f2(x,y,z)   ( x ^ y ^ z )                       /* Rounds 20-39 */
-#define f3(x,y,z)   ( ( x & y ) | ( z & ( x | y ) ) )   /* Rounds 40-59 */
-#define f4(x,y,z)   ( x ^ y ^ z )                       /* Rounds 60-79 */
+#define f1(x,y,z)   ( (z) ^ ( (x) & ( (y) ^ (z) ) ) )   /* Rounds  0-19 */
+#define f2(x,y,z)   ( (x) ^ (y) ^ (z) )                 /* Rounds 20-39 */
+#define f3(x,y,z)   ( ( (x) & (y) ) | ( (z) & ( (x) | (y) ) ) )   /* Rounds 40-59 */
+#define f4(x,y,z)   ( (x) ^ (y) ^ (z) )                 /* Rounds 60-79 */
 
 /* The SHA Mysterious Constants */
 
@@ -97,9 +97,9 @@
    bit.  Thanks to Jim Gillogly, jim@rand.org, and an anonymous contributor
    for this information */
 
-#define expand(W,i) ( W[ i & 15 ] = \
-		      ROTL( 1, ( W[ i & 15 ] ^ W[ (i - 14) & 15 ] ^ \
-				 W[ (i - 8) & 15 ] ^ W[ (i - 3) & 15 ] ) ) )
+#define expand(W,i) ( W[ (i) & 15 ] = \
+		      ROTL( 1, ( W[ (i) & 15 ] ^ W[ ((i) - 14) & 15 ] ^ \
+				 W[ ((i) - 8) & 15 ] ^ W[ ((i) - 3) & 15 ] ) ) )
 
 
 /* The prototype SHA sub-round.  The fundamental sub-round is:
