diff -urPN --exclude=CVS --exclude=.svn --exclude=00_TRANS.TBL export/home/cy/freebsd/fwbuilder/work/fwbuilder-3.0.7/src/pflib/PolicyCompiler_pf.cpp usr/ports/security/fwbuilder.old/work/fwbuilder-3.0.6/src/pflib/PolicyCompiler_pf.cpp
--- src/pflib/PolicyCompiler_pf.cpp	2009-09-18 12:28:39.000000000 -0700
+++ src/pflib/PolicyCompiler_pf.cpp	2009-08-18 08:27:52.000000000 -0700
@@ -521,8 +521,7 @@
 {
     PolicyRule *rule=getNext(); if (rule==NULL) return false;
 
-    if (rule->getDirection()==PolicyRule::Both &&
-        rule->getAction()==PolicyRule::Route)
+    if (rule->getDirection()==PolicyRule::Both)
     {
 	PolicyRule *r= compiler->dbcopy->createPolicyRule();
 	compiler->temp_ruleset->add(r);
