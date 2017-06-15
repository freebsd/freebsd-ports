https://github.com/emweb/wt/pull/102

--- src/Wt/Render/CssParser.C.orig	2016-07-13 12:27:26 UTC
+++ src/Wt/Render/CssParser.C
@@ -372,7 +372,7 @@ CssGrammer<Iterator>::CssGrammer()
   on_error<qi::fail>
   (
     rulesetArray_,
-    error_report(qi::_2, qi::_3, qi::_4, "styleSheetText()", fs_error_tag())
+    error_report(qi::_2, qi::_3, qi::_4, phoenix::val("styleSheetText()"), fs_error_tag())
   );
 
 }
