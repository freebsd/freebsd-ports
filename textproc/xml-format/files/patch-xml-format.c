--- xml-format.c.orig	2025-02-05 15:23:48 UTC
+++ xml-format.c
@@ -13,6 +13,7 @@
  *  2013-02-09  Jason Bacon Begin
  ***************************************************************************/
 
+#include <errno.h>
 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
@@ -69,7 +70,6 @@ int xml_format(const char *filename)
 	    buff[COPY_BUFF_SIZE+1],
 	    *subdir;
     size_t  bytes;
-    extern int  errno;
     tag_list_t  tags;
     
     if ( ( subdir = strrchr(filename, '.')) == NULL )
