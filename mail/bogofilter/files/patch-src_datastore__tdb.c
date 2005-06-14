--- a/src/datastore_tdb.c	31 May 2005 15:04:05 -0000	1.51.22.1
+++ b/src/datastore_tdb.c	10 Jun 2005 08:19:30 -0000	1.51.22.2
@@ -268,20 +268,34 @@
     dbv_t dbv_key, dbv_data;
     userdata_t *hookdata = userdata;
 
-    /* Question: Is there a way to avoid using malloc/free? */
-
-    /* switch to "dbv_t *" variables */
+    /* TDB happily returns data from odd addresses, so we need to
+     * memcpy() everything to properly aligned storage (malloc() is
+     * fine) if our callee wishes to perform word-sized access - without
+     * memcpy(), the callee will die with SIGBUS (SPARC, m68k) or get
+     * extremely slow (i386). */
+
+    /* XXX FIXME: Possible optimization if this function is only used by
+     * one caller at a time (i. e. no threads): allocate buffers
+     * statically and reuse them as long as they are of sufficient size
+     * and reallocate otherwise. */
+
+    /* copy key */
+    /* XXX FIXME: do we really need to use C-string compatible keys?
+     * Looks wasteful. */
     dbv_key.leng = key.dsize;
     dbv_key.data = xmalloc(dbv_key.leng+1);
     memcpy(dbv_key.data, key.dptr, dbv_key.leng);
     ((char *)dbv_key.data)[dbv_key.leng] = '\0';
 
-    dbv_data.data = data.dptr;
-    dbv_data.leng = data.dsize;		/* read count */
+    /* copy data */
+    dbv_data.leng = data.dsize;
+    dbv_data.data = xmalloc(dbv_data.leng);
+    memcpy(dbv_data.data, data.dptr, dbv_data.leng);
 
     /* call user function */
     rc = hookdata->hook(&dbv_key, &dbv_data, hookdata->userdata);
 
+    xfree(dbv_data.data);
     xfree(dbv_key.data);
 
     return rc;
