--- diffstat.c.orig	2010-08-10 19:27:19.414564698 +0200
+++ diffstat.c	2010-08-10 19:28:49.625931506 +0200
@@ -1934,7 +1934,7 @@ is_compressed(const char *name)
     } else if (len > 5 && !strcmp(name + len - 5, ".lzma")) {
 	which = dcLzma;
     } else if (len > 3 && !strcmp(name + len - 3, ".xz")) {
-	which = dcLzma;
+	which = dcXz;
     } else {
 	which = dcNone;
     }
