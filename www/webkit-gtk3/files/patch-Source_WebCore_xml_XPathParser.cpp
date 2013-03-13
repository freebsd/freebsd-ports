--- Source/WebCore/xml/XPathParser.cpp.orig	2011-08-06 10:38:59.000000000 +0000
+++ Source/WebCore/xml/XPathParser.cpp	2013-02-26 10:11:22.000000000 +0000
@@ -34,24 +34,21 @@
 #include "XPathEvaluator.h"
 #include "XPathException.h"
 #include "XPathNSResolver.h"
+#include "XPathPath.h"
 #include "XPathStep.h"
 #include <wtf/StdLibExtras.h>
 #include <wtf/text/StringHash.h>
 
-int xpathyyparse(void*);
-
+using namespace WebCore;
 using namespace WTF;
 using namespace Unicode;
+using namespace XPath;
 
-namespace WebCore {
-namespace XPath {
-
-class LocationPath;
-
-#include "XPathGrammar.h"    
+extern int xpathyyparse(WebCore::XPath::Parser*);
+#include "XPathGrammar.h"
 
 Parser* Parser::currentParser = 0;
-    
+
 enum XMLCat { NameStart, NameCont, NotPartOfName };
 
 typedef HashMap<String, Step::Axis> AxisNamesMap;
@@ -632,7 +629,5 @@
     delete t;
 }
 
-}
-}
 
 #endif // ENABLE(XPATH)

