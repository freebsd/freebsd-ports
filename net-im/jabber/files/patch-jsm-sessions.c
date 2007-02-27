--- jsm/sessions.c.orig	Fri Feb  9 11:27:52 2007
+++ jsm/sessions.c	Fri Feb  9 11:45:32 2007
@@ -105,7 +105,9 @@
  */
 static void _js_create_session_id(char resultbuffer[9], xht existing_sessions) {
     static int seeded = 0;
+#ifdef _GLIBC_
     static struct drand48_data rand_state;
+#endif
     long int rand_value;
     int tries = 256;
 
@@ -118,13 +120,21 @@
 	seed_data[0] = now.tv_sec%0x10000;
 	seed_data[1] = now.tv_sec/0x10000;
 	seed_data[2] = now.tv_usec%0x10000;
+#ifdef _GLIBC_
 	seed48_r(seed_data, &rand_state);
+#else
+	seed48(seed_data);
+#endif
 	seeded = 1;
     }
 
     /* create an ID, that is not already used */
     while (tries--) {
+#ifdef _GLIBC_
 	lrand48_r(&rand_state, &rand_value);
+#else
+	rand_value = lrand48();
+#endif
 	snprintf(resultbuffer, 9, "%lx", rand_value);
 
 	if (existing_sessions == NULL || xhash_get(existing_sessions, resultbuffer) == NULL)
