
$FreeBSD$

--- libs/spool/flatfile/sge_spooling_flatfile_scanner.h.orig
+++ libs/spool/flatfile/sge_spooling_flatfile_scanner.h
@@ -32,6 +32,7 @@
  ************************************************************************/
 /*___INFO__MARK_END__*/       
 
+#include <sys/types.h>
 #include <stdio.h>
 
 typedef enum {
