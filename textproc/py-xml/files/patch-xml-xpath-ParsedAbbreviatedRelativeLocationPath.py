--- xml/xpath/ParsedAbbreviatedRelativeLocationPath.py.orig	2009-07-09 08:43:39.000000000 +0800
+++ xml/xpath/ParsedAbbreviatedRelativeLocationPath.py	2009-07-09 08:43:56.000000000 +0800
@@ -28,8 +28,8 @@
         self._right = right
         nt = ParsedNodeTest.ParsedNodeTest('node','')
         ppl = ParsedPredicateList.ParsedPredicateList([])
-        as = ParsedAxisSpecifier.ParsedAxisSpecifier('descendant-or-self')
-        self._middle = ParsedStep.ParsedStep(as, nt, ppl)
+        as26 = ParsedAxisSpecifier.ParsedAxisSpecifier('descendant-or-self')
+        self._middle = ParsedStep.ParsedStep(as26, nt, ppl)
 
     def evaluate(self, context):
         res = []
