--- src/base/fileRepository.h.orig	2015-10-05 06:33:52 UTC
+++ src/base/fileRepository.h
@@ -23,6 +23,7 @@
 #define FILEREPOSITORY_H_
 
 #include <stdio.h>
+#include <unistd.h>
 
 #include "definition.h"
 #include "mediaRepository.h"
