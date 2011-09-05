--- tests/template_WriteHeaderEntries.phpt.orig	2011-09-05 11:27:46.000000000 +0800
+++ tests/template_WriteHeaderEntries.phpt	2011-09-05 11:28:15.000000000 +0800
@@ -10,8 +10,8 @@ echo $tpl->WriteHeaderEntries();
 ===DONE===
 --EXPECTF--
 #include <ctemplate/template_string.h>
-static const StaticTemplateString ke_NAME = STS_INIT_WITH_HASH(ke_NAME, "NAME", 11433977280339851189LLU);
-static const StaticTemplateString ke_VALUE = STS_INIT_WITH_HASH(ke_VALUE, "VALUE", 3571384048577261229LLU);
-static const StaticTemplateString ke_IN_CA = STS_INIT_WITH_HASH(ke_IN_CA, "IN_CA", 15931064057564334051LLU);
-static const StaticTemplateString ke_TAXED_VALUE = STS_INIT_WITH_HASH(ke_TAXED_VALUE, "TAXED_VALUE", 10685086013714446631LLU);
+static const ::ctemplate::StaticTemplateString ke_NAME = STS_INIT_WITH_HASH(ke_NAME, "NAME", 11433977280339851189LLU);
+static const ::ctemplate::StaticTemplateString ke_VALUE = STS_INIT_WITH_HASH(ke_VALUE, "VALUE", 3571384048577261229LLU);
+static const ::ctemplate::StaticTemplateString ke_IN_CA = STS_INIT_WITH_HASH(ke_IN_CA, "IN_CA", 15931064057564334051LLU);
+static const ::ctemplate::StaticTemplateString ke_TAXED_VALUE = STS_INIT_WITH_HASH(ke_TAXED_VALUE, "TAXED_VALUE", 10685086013714446631LLU);
 ===DONE===
