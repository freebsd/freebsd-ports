Use the modern random(3) and device-based seeding.

	-mi

--- src/rand.c	2009-11-18 07:23:18.000000000 -0500
+++ src/rand.c	2013-02-12 16:09:01.000000000 -0500
@@ -1,26 +1,18 @@
 #include "super.h"
 
-int myrand(void)
-{
-	struct timeval tv;
-	unsigned int seed;
-
-	gettimeofday(&tv, (struct timezone *) 0);
-	seed = (tv.tv_sec % 10000) * 523 + tv.tv_usec * 13 + (getpid() % 1000) * 983;
-	srand(seed);
-
-	return rand();
-}
-
-char *rand2str(size_t len)
+const char *
+rand2str(size_t len)
 {
 	static char buf[BUFSIZ];
 	char *ptr = buf;
-	char *alphabet =
+	char alphabet[] =
 	"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
-	int i;
+	size_t i;
+
+	if (len == 0)
+		return NULL;
 
-	if (len < 0)
-		return (char *) 0;
+	if (buf[0] == '\0') /* First time we are here */
+		srandomdev(); /* Seed */
 
 	if (len >= BUFSIZ)
@@ -28,5 +20,5 @@
 
 	for (i = 0; i < len; i++) {
-		int j = (myrand() & 0xffff) % (26 + 26 + 10);
+		int j = random() % (sizeof(alphabet)/sizeof(char) - 1);
 		ptr[i] = alphabet[j];
 	}
