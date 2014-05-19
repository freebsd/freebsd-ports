--- src/doc/common/builder.py.orig	2014-05-06 11:21:42.000000000 +0000
+++ src/doc/common/builder.py	2014-05-15 21:18:06.000000000 +0000
@@ -281,19 +281,22 @@
 
         # build the other documents in parallel
         from multiprocessing import Pool
-        pool = Pool(NUM_THREADS, maxtasksperchild=1)
+        # pool = Pool(NUM_THREADS, maxtasksperchild=1)
         L = [(doc, name, kwds) + args for doc in others]
-        # map_async handles KeyboardInterrupt correctly. Plain map and
-        # apply_async does not, so don't use it.
-        x = pool.map_async(build_other_doc, L, 1)
-        try:
-            x.get(99999)
-            pool.close()
-            pool.join()
-        except Exception:
-            pool.terminate()
-            if ABORT_ON_ERROR:
-                raise
+        # Pool doesn't work properly in FreeBSD.  Instead:
+        for iii in L:
+            build_other_doc(iii)
+        # # map_async handles KeyboardInterrupt correctly. Plain map and
+        # # apply_async does not, so don't use it.
+        # x = pool.map_async(build_other_doc, L, 1)
+        # try:
+        #     x.get(99999)
+        #     pool.close()
+        #     pool.join()
+        # except Exception:
+        #     pool.terminate()
+        #     if ABORT_ON_ERROR:
+        #         raise
         logger.warning("Elapsed time: %.1f seconds."%(time.time()-start))
         logger.warning("Done building the documentation!")
 
@@ -479,18 +482,20 @@
                 continue
             output_dir = self._output_dir(format, lang)
             from multiprocessing import Pool
-            pool = Pool(NUM_THREADS, maxtasksperchild=1)
+            # pool = Pool(NUM_THREADS, maxtasksperchild=1)
             L = [(doc, lang, format, kwds) + args for doc in self.get_all_documents(refdir)]
             # (See comment in AllBuilder._wrapper about using map instead of apply.)
-            x = pool.map_async(build_ref_doc, L, 1)
-            try:
-                x.get(99999)
-                pool.close()
-                pool.join()
-            except Exception:
-                pool.terminate()
-                if ABORT_ON_ERROR:
-                    raise
+            for iii in L:
+                build_ref_doc(iii)
+            # x = pool.map_async(build_ref_doc, L, 1)
+            # try:
+            #     x.get(99999)
+            #     pool.close()
+            #     pool.join()
+            # except Exception:
+            #     pool.terminate()
+            #     if ABORT_ON_ERROR:
+            #         raise
             # The html refman must be build at the end to ensure correct
             # merging of indexes and inventories.
             # Sphinx is run here in the current process (not in a
