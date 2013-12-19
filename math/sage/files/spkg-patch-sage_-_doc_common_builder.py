--- sage-5.8.rc0/doc/common/builder.py-orig	2013-03-17 20:50:38.000000000 +0000
+++ sage-5.13/doc/common/builder.py	2013-03-17 20:56:42.000000000 +0000
@@ -272,13 +272,16 @@
 
         # build the other documents in parallel
         from multiprocessing import Pool
-        pool = Pool(NUM_THREADS, maxtasksperchild=1)
+        # pool = Pool(NUM_THREADS, maxtasksperchild=1)
         L = [(doc, name, kwds) + args for doc in others]
-        # map_async handles KeyboardInterrupt correctly. Plain map and
-        # apply_async does not, so don't use it.
-        pool.map_async(build_other_doc, L, 1).get(99999)
-        pool.close()
-        pool.join()
+        # Pool doesn't work properly in FreeBSD.  Instead:
+        for iii in L:
+            build_other_doc(iii)
+        # # map_async handles KeyboardInterrupt correctly. Plain map and
+        # # apply_async does not, so don't use it.
+        # pool.map_async(build_other_doc, L, 1).get(99999)
+        # pool.close()
+        # pool.join()
         logger.warning("Elapsed time: %.1f seconds."%(time.time()-start))
         logger.warning("Done building the documentation!")
 
@@ -464,12 +467,15 @@
                 continue
             output_dir = self._output_dir(format, lang)
             from multiprocessing import Pool
-            pool = Pool(NUM_THREADS, maxtasksperchild=1)
+            # pool = Pool(NUM_THREADS, maxtasksperchild=1)
             L = [(doc, lang, format, kwds) + args for doc in self.get_all_documents(refdir)]
-            # (See comment in AllBuilder._wrapper about using map instead of apply.)
-            pool.map_async(build_ref_doc, L, 1).get(99999)
-            pool.close()
-            pool.join()
+            # Pool doesn't work properly in FreeBSD.  Instead:
+            for iii in L:
+                build_ref_doc(iii)
+            # # (See comment in AllBuilder._wrapper about using map instead of apply.)
+            # pool.map_async(build_ref_doc, L, 1).get(99999)
+            # pool.close()
+            # pool.join()
             # The html refman must be build at the end to ensure correct
             # merging of indexes and inventories.
             # Sphinx is run here in the current process (not in a
