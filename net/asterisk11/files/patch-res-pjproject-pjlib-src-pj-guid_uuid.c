--- res/pjproject/pjlib/src/pj/guid_uuid.c-orig	2013-07-03 14:46:46.000000000 +0200
+++ res/pjproject/pjlib/src/pj/guid_uuid.c	2013-07-03 14:47:11.000000000 +0200
@@ -23,7 +23,7 @@
 #include <pj/os.h>
 #include <pj/string.h>
 
-#include <uuid/uuid.h>
+#include <uuid.h>
 
 PJ_DEF_DATA(const unsigned) PJ_GUID_STRING_LENGTH=36;
