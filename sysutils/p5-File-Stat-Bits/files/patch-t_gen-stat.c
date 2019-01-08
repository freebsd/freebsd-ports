--- t/gen-stat.c.orig	2006-06-28 11:54:00 UTC
+++ t/gen-stat.c
@@ -48,9 +48,9 @@
 /* - shamelessly stolen from other source headers */
 
 
-static void pr(const char *name, unsigned long value)
+static void pr(const char *name, dev_t value)
 {
-    printf("sub %-12s () { 0%06lo }\n", name, value);
+    printf("sub %-12s () { 0%06llo }\n", name, value);
 }
 
 static void prundef(const char *name)
@@ -113,13 +113,13 @@ static void constants(void)
 
 #ifdef _HAVE_MAJOR_MINOR
 
-#define MASK(bit) ( ((unsigned long)1) << (bit) )
+#define MASK(bit) ( ((dev_t)1) << (bit) )
 
-static void test(unsigned long (*f)(unsigned long),
-		 unsigned long *_mask, unsigned int *_shift)
+static void test(dev_t (*f)(dev_t),
+		 dev_t *_mask, unsigned int *_shift)
 {
     unsigned int shift;
-    unsigned long mask, old_mask;
+    dev_t mask, old_mask;
 
     for(shift=0; mask=MASK(shift), f(mask) == 0; ++shift)
 	;
@@ -137,12 +137,12 @@ static void test(unsigned long (*f)(unsigned long),
 }
 
 
-static unsigned long Major( unsigned long dev )
+static dev_t Major( dev_t dev )
 {
     return major(dev);
 }
 
-static unsigned long Minor( unsigned long dev )
+static dev_t Minor( dev_t dev )
 {
     return minor(dev);
 }
@@ -153,7 +153,7 @@ static unsigned long Minor( unsigned long dev )
 int main(void)
 {
 #ifdef _HAVE_MAJOR_MINOR
-    unsigned long major_mask , minor_mask;
+    dev_t major_mask , minor_mask;
     unsigned int  major_shift, minor_shift;
 
     test( Major, &major_mask, &major_shift );
