--- nsprpub/pr/src/misc/prnetdb.c	16 Jan 2003 23:09:16 -0000	3.21.2.8
+++ nsprpub/pr/src/misc/prnetdb.c	25 Jan 2003 00:12:13 -0000
@@ -319,7 +319,7 @@
     PR_Free(buf);
 }
 
-#elif (defined(DARWIN) && defined(HAVE_GETIFADDRS))
+#elif (defined(DARWIN) && defined(HAVE_GETIFADDRS)) || defined(FREEBSD)
 
 /*
  * Use the BSD getifaddrs function.
