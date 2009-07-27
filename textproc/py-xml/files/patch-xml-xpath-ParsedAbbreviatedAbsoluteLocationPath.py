--- xml/xpath/ParsedAbbreviatedAbsoluteLocationPath.py.orig	2009-07-09 08:48:55.000000000 +0800
+++ xml/xpath/ParsedAbbreviatedAbsoluteLocationPath.py	2009-07-09 08:49:09.000000000 +0800
@@ -24,8 +24,8 @@
         self._rel = rel
         nt = ParsedNodeTest.ParsedNodeTest('node', '')
         ppl = ParsedPredicateList.ParsedPredicateList([])
-        as = ParsedAxisSpecifier.ParsedAxisSpecifier('descendant-or-self')
-        self._step = ParsedStep.ParsedStep(as, nt, ppl)
+        as26 = ParsedAxisSpecifier.ParsedAxisSpecifier('descendant-or-self')
+        self._step = ParsedStep.ParsedStep(as26, nt, ppl)
         return
 
     def evaluate(self, context):
