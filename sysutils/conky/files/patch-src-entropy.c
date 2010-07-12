--- src/entropy.c.orig
+++ src/entropy.c
@@ -49,10 +49,11 @@ static struct {
 	.poolsize = 0,
 };
 
-void update_entropy(void)
+int update_entropy(void)
 {
 	get_entropy_avail(&entropy.avail);
 	get_entropy_poolsize(&entropy.poolsize);
+	return 0;
 }
 
 void print_entropy_avail(struct text_object *obj, char *p, int p_max_size)
