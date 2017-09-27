--- extensions/apps.vala.orig	2015-08-30 11:56:26 UTC
+++ extensions/apps.vala
@@ -265,7 +265,11 @@ namespace Apps {
                             store.get (iter, 0, out launcher);
                             try {
                                 launcher.file.trash (null);
+#if VALA_0_36
+                                store.remove (ref iter);
+#else
                                 store.remove (iter);
+#endif
 
                                 string filename = Midori.Download.clean_filename (launcher.name);
 #if HAVE_WIN32
