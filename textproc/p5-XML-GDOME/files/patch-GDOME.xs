--- GDOME.xs.orig	2003-12-02 09:30:40 UTC
+++ GDOME.xs
@@ -8,7 +8,9 @@ extern "C" {
 #include "XSUB.h"
 
 /*#include <libxml/hash.h>*/
+#include <libxml/tree.h>
 #include <libxml/xmlerror.h>
+#include <libxml/xmlstring.h>
 #include "gdome.h"
 #include "gdome-xpath.h"
 /*#include "gdome-traversal.h"
