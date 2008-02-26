--- src/tools/enumpoly/pelqhull.cc.orig	2008-02-20 19:44:12.000000000 +0100
+++ src/tools/enumpoly/pelqhull.cc	2008-02-20 19:51:31.000000000 +0100
@@ -939,7 +939,7 @@
   else {
     SETreturnsize_(set, size);
     fprintf (fp, "%s set=%x maxsize=%d size=%d elems=",
-	     string, (unsigned int) set, set->maxsize, size);
+	     string, (size_t) set, set->maxsize, size);
     if (size > (int)set->maxsize)
       size= set->maxsize+1;
     for (k=0; k<size; k++)
