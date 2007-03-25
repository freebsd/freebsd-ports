
$FreeBSD$

--- os_freebsd.cpp.orig
+++ os_freebsd.cpp
@@ -1008,7 +1008,7 @@
   // to first list. Turn on NOCHECK for second call. This results in no
   // error if no more matches found, however it does append the actual
   // pattern to the list of paths....
-  if ((retglob=glob(pattern1, GLOB_ERR, NULL, &globbuf)) ||
+  if ((retglob=glob(pattern1, GLOB_ERR|GLOB_NOCHECK, NULL, &globbuf)) ||
       (retglob=glob(pattern2, GLOB_ERR|GLOB_APPEND|GLOB_NOCHECK,NULL,&globbuf))) {
      int retval = -1;
     // glob failed
