--- TailFile.h.orig	Wed Aug  4 04:42:33 1999
+++ TailFile.h	Thu Feb  5 19:49:47 2004
@@ -23,7 +23,8 @@
 #include "Colorizer.h"
 
 #include <stdio.h>
-#include <strstream.h>
+#include <iostream>
+#include <strstream>
 
 #define MAX_CHARS_READ 1024
 
@@ -40,7 +41,7 @@
    // the stream position
    long m_position;
    // the follow buffer, used in follow_print
-   ostrstream *m_follow_buffer;
+   std::ostrstream *m_follow_buffer;
 
    // private methods
    void find_position(int n);
