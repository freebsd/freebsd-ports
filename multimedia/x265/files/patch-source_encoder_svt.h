https://bitbucket.org/multicoreware/x265/issues/509/x265-fails-to-build-with-current-svt-hevc

In file included from source/encoder/analysis.cpp:35:
In file included from source/encoder/encoder.h:34:
source/encoder/svt.h:32:10: fatal error: 'EbTime.h' file not found
#include "EbTime.h"
         ^~~~~~~~~~

--- source/encoder/svt.h.orig	2019-07-31 04:59:54 UTC
+++ source/encoder/svt.h
@@ -29,7 +29,6 @@
 
 #include "EbApi.h"
 #include "EbErrorCodes.h"
-#include "EbTime.h"
 
 namespace X265_NS {
 
