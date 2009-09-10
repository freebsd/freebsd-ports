Description: Protect some macro parameters with parentheses.
Author: Peter Pentchev <roam@FreeBSD.org>
Forwarded: http://sourceforge.net/mailarchive/message.php?msg_name=20090910102100.GA26539%40straylight.m.ringlet.net
Last-Update: 2009-09-10

--- lib/sha1.c.orig
+++ lib/sha1.c
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
