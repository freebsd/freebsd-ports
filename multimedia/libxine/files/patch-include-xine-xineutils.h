--- include/xine/xineutils.h.orig
+++ include/xine/xineutils.h
@@ -146,7 +146,7 @@ void *xine_xcalloc(size_t nmemb, size_t 
  * Free allocated memory and set pointer to NULL
  * @param ptr Pointer to the pointer to the memory block which should be freed.
  */
-static inline void _x_freep(void *ptr) {
+static void _x_freep(void *ptr) {
   void **p = (void **)ptr;
   free (*p);
   *p = NULL;
