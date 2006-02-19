--- cairo/src/cairo-ft-font.c.orig	Mon Aug 29 14:11:27 2005
+++ cairo/src/cairo-ft-font.c	Sun Sep 11 00:44:30 2005
@@ -44,6 +44,11 @@
 #include <fontconfig/fontconfig.h>
 #include <fontconfig/fcfreetype.h>
 
+#include <sys/types.h>
+#include <stdlib.h>
+#include <time.h>
+#include <unistd.h>
+
 #include <ft2build.h>
 #include FT_FREETYPE_H
 #include FT_OUTLINE_H
@@ -278,7 +283,12 @@
     key->id = id;
 
     /* 1607 is just an arbitrary prime. */
-    hash = _cairo_hash_string (filename);
+    if (filename != NULL) {
+	hash = _cairo_hash_string (filename);
+    } else {
+	srandom(time(NULL) * getpid());
+	hash = random();
+    }
     hash += ((unsigned long) id) * 1607;
 	
     key->base.hash_entry.hash = hash;
