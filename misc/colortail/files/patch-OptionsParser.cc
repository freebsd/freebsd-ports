--- OptionsParser.cc.orig	Thu Aug  5 08:23:39 1999
+++ OptionsParser.cc	Thu Feb  5 19:49:47 2004
@@ -18,7 +18,7 @@
 */
 
 #include <iostream.h>
-#include <strstream.h>
+#include <strstream>
 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -130,7 +130,7 @@
 	    int loop = 1;
 	    while (loop)
 	    {
-	       ostrstream filename;
+	       std::ostrstream filename;
 
 	       while (1)
 	       {
