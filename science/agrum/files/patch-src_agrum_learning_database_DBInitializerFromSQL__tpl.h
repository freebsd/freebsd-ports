--- src/agrum/learning/database/DBInitializerFromSQL_tpl.h.orig	2018-12-20 05:55:07 UTC
+++ src/agrum/learning/database/DBInitializerFromSQL_tpl.h
@@ -26,6 +26,8 @@
 
 #ifdef _ODBC
 
+#include <clocale> // https://gitlab.com/agrumery/aGrUM/issues/23
+
 #  ifndef DOXYGEN_SHOULD_SKIP_THIS
 
 #    include <agrum/learning/database/DBInitializerFromSQL.h>
