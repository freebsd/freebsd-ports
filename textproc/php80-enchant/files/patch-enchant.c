--- enchant.c.orig	2020-10-18 21:29:39 UTC
+++ enchant.c
@@ -24,7 +24,7 @@
 #include "ext/standard/info.h"
 #include "Zend/zend_interfaces.h"
 #include "Zend/zend_exceptions.h"
-#include "../spl/spl_exceptions.h"
+#include "ext/spl/spl_exceptions.h"
 #include <enchant.h>
 #include "php_enchant.h"
 #include "enchant_arginfo.h"
