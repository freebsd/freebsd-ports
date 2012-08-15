--- ./runsamples.py.orig	2012-08-15 14:44:29.000000000 +0200
+++ ./runsamples.py	2012-08-15 14:44:45.000000000 +0200
@@ -41,6 +41,8 @@
   logging.getLogger().setLevel(getattr(logging, FLAGS.logging_level))
 
   for dirname in os.listdir(FLAGS.sample_root):
+    if not os.path.isdir(dirname):
+      continue
     fulldirname = os.path.join(FLAGS.sample_root, dirname)
     if dirname in FLAGS.samples_to_skip:
       logging.debug('Skipping ' + fulldirname + ' (blacklist)')
