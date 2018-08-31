Unbreak build of phonon-xine

In file included from xine/plugins.c:23:
In file included from /usr/local/include/xine/input_plugin.h:27:
/usr/local/include/xine/xineutils.h:197:8: error: unknown type name 'inline'
static inline void _x_freep(void *ptr) {
       ^
/usr/local/include/xine/xineutils.h:197:15: error: expected identifier or '('
static inline void _x_freep(void *ptr) {
              ^

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
