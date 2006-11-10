--- src/sequence/Sequence.cpp.orig	Fri Nov  3 10:59:39 2006
+++ src/sequence/Sequence.cpp	Fri Nov  3 10:59:18 2006
@@ -214,7 +214,7 @@
 
   Sequence result(context->getMemoryManager());
 
-  const_iterator end(end());
+  Sequence::const_iterator end(Sequence::end());
   for(const_iterator i = begin(); i != end; ++i) 
   {
 	  if((*i)->isNode())
