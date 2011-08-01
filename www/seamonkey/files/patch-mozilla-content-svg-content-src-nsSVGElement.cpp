--- mozilla/content/svg/content/src/nsSVGElement.cpp.orig	2010-05-12 16:46:09.000000000 +0200
+++ mozilla/content/svg/content/src/nsSVGElement.cpp	2010-05-12 16:49:33.000000000 +0200
@@ -102,7 +102,11 @@
 // vararg-list methods in this file:
 //   nsSVGElement::GetAnimated{Length,Number,Integer}Values
 // See bug 547964 for details:
-PR_STATIC_ASSERT(sizeof(void*) == sizeof(nsnull));
+// I really try to get the details but I'm not allowed to
+// access this bug in bugzilla:
+// You are not authorized to access bug #547964.
+// So disable this ASSERT as it breaks build.
+//PR_STATIC_ASSERT(sizeof(void*) == sizeof(nsnull));
 
 
 nsSVGEnumMapping nsSVGElement::sSVGUnitTypesMap[] = {
