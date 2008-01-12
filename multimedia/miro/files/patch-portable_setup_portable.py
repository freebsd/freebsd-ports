--- ./portable/setup_portable.py.orig	2008-01-10 20:55:52.000000000 +0100
+++ ./portable/setup_portable.py	2008-01-11 22:35:18.000000000 +0100
@@ -182,6 +182,7 @@
         return Extension("miro.libtorrent", 
                          include_dirs = include_dirs,
                          libraries = librariestype,
+                         library_dirs = ['BOOST_LIB_PATH'],
                          extra_compile_args = EXTRA_COMPILE_ARGS,
                          sources = sources)
     else:
