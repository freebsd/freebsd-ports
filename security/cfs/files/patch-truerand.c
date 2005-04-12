
$FreeBSD$

--- truerand.c.orig
+++ truerand.c
@@ -89,6 +89,8 @@
 #include <math.h>
 #include <stdio.h>
 
+#include <inttypes.h>
+
 static jmp_buf env;
 static unsigned count;
 static unsigned ocount;
@@ -115,7 +117,7 @@
 	tick();
 }
 
-static unsigned long
+static uint32_t
 roulette()
 {
 	if (setjmp(env))
@@ -131,15 +133,15 @@
  * basic interface to 32 bit truerand.
  * note that any scheduled SIGALRM will be delayed by about .3 secs.
  */
-unsigned long
+uint32_t
 raw_truerand()
 {
 	void (*oldalrm)();
 	struct itimerval it;
-	unsigned long counts[12];
+	uint32_t counts[12];
 	unsigned char *qshs();
 	unsigned char *r;
-	unsigned long buf;
+	uint32_t buf;
 	int i;
 
 	getitimer(ITIMER_REAL, &it);
@@ -153,7 +155,7 @@
 	setitimer(ITIMER_REAL, &it, NULL);
 
 	r = qshs(counts,sizeof(counts));
-	buf = *((unsigned long *) r);
+	buf = *((uint32_t *) r);
 
 	return buf;
 }
@@ -182,8 +184,8 @@
  *	usage: 
  *		unsigned char r8;
  *		unsigned short r16;
- *		unsigned long r32;
- *		unsigned long trand8(), trand16(), trand32();
+ *		uint32_t r32;
+ *		uint32_t trand8(), trand16(), trand32();
  *		r8=trand8();
  *		r16=trand16();
  *		r32=trand32();
@@ -206,11 +208,11 @@
  * OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
  */
 
-unsigned long randbyte()
+uint32_t randbyte()
 {
-	unsigned long raw_truerand();
+	uint32_t raw_truerand();
 	unsigned char *qshs();
-	unsigned long r[2];
+	uint32_t r[2];
 	unsigned char *hash;
 
 	r[0]=raw_truerand(); r[1]=raw_truerand();
@@ -218,17 +220,17 @@
 	return ((int) (*hash)) & 0xff;
 }
 
-unsigned long trand8()
+uint32_t trand8()
 {
 	return randbyte();
 }
 
-unsigned long trand16()
+uint32_t trand16()
 {
 	return randbyte() ^ (randbyte()<<8);
 }
 
-unsigned long trand32()
+uint32_t trand32()
 {
 	return randbyte() ^ (randbyte()<<8)
 		^ (randbyte()<<16) ^ (randbyte()<<24);
