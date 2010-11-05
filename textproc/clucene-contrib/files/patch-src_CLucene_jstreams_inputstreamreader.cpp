--- src/CLucene/jstreams/inputstreamreader.cpp	Sat Feb 10 13:56:34 2007
+++ src/CLucene/jstreams/inputstreamreader.cpp.orig	Fri Nov 24 13:42:02 2006
@@ -13,7 +13,7 @@
 #ifndef ICONV_CONST
      //we try to guess whether the iconv function requires
      //a const char. We have no way of automatically figuring
-     //this out if we didnt use autoconf, so we guess based
+     //this out if we did not use autoconf, so we guess based
      //on certain parameters:
      #ifdef _LIBICONV_H
           #define ICONV_CONST const
@@ -49,7 +49,7 @@
         return;
     }
     charbuf.setSize(262);
-    mark(262);
+    //mark(262);
     charsLeft = 0;
 }
 InputStreamReader::~InputStreamReader() {
@@ -86,7 +86,7 @@
             nwritten = space;
             break;
         default:
-            exit(-1);
+            printf("InputStreamReader::error %d\n", errno);
         }
     } else { //input sequence was completely converted
         charbuf.readPos = charbuf.start;
