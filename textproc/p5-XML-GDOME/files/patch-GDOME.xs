--- GDOME.xs~	Sat Nov 15 23:50:50 2003
+++ GDOME.xs	Sun Sep 15 17:59:40 2002
@@ -7,6 +7,7 @@
 #include "perl.h"
 #include "XSUB.h"
 
+#include <libxml/parser.h>
 #include <libxml/hash.h>
 #include <libxml/xmlerror.h>
 #include "gdome.h"
