
$FreeBSD$

--- scripts/miscellaneous/unpack.m.orig
+++ scripts/miscellaneous/unpack.m
@@ -124,19 +124,13 @@
     commandlist.tar = {"tar -x -v -f \"%s\"", ...
 		       "tar -x -f \"%s\"", ...
 		       @__parse_tar__, false};
-    commandlist.targz = {"gzip -d -c \"%s\" | tar -x -v", ...
-			 "gzip -d -c \"%s\" | tar -x", ...
-			 @__parse_tar__, false};
-    commandlist.tgz = commandlist.targz;
-    commandlist.tarbz2 = {"bzip2 -d -c \"%s\" | tar -x -v", ...
-			  "bzip2 -d -c \"%s\" | tar -x", ...
-			  @__parse_tar__, false};
-    commandlist.tarbz = commandlist.tarbz2;
-    commandlist.tbz2 = commandlist.tarbz2;
-    commandlist.tbz = commandlist.tarbz2;
-    commandlist.zip = {"unzip \"%s\"", ...
-		       "unzip -q \"%s\"", ...
-		       @__parse_zip__, false};
+    commandlist.targz = commandlist.tar;
+    commandlist.tgz = commandlist.tar;
+    commandlist.tarbz2 = commandlist.tar;
+    commandlist.tarbz = commandlist.tar;
+    commandlist.tbz2 = commandlist.tar;
+    commandlist.tbz = commandlist.tar;
+    commandlist.zip = commandlist.tar;
   endif
 
   nodotext = ext(! ismember (ext, "."));
