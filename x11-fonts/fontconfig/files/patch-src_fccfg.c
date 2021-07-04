From df29933e1a06b7aa7af229bd7cd03c62d957f15f Mon Sep 17 00:00:00 2001
From: Szunti <Szunti@users.noreply.github.com>
Date: Sun, 6 Dec 2020 12:52:44 +0100
Subject: [PATCH] Check qual and compare for family tests

Fixes #267. Hash table lookups assumed qual="any" compare="eq".
Add a test too.
--- src/fccfg.c.orig	2020-11-28 01:56:42 UTC
+++ src/fccfg.c
@@ -1714,6 +1714,7 @@ FcConfigMatchValueList (FcPattern	*p,
     FcExpr	    *e = t->expr;
     FcValue	    value;
     FcValueList	    *v;
+    FcOp            op;
 
     while (e)
     {
@@ -1731,10 +1732,23 @@ FcConfigMatchValueList (FcPattern	*p,
 
         if (t->object == FC_FAMILY_OBJECT && table)
         {
-            if (!FamilyTableLookup (table, t->op, FcValueString (&value)))
+            op = FC_OP_GET_OP (t->op);
+            if (op == FcOpEqual || op == FcOpListing)
             {
+                if (!FamilyTableLookup (table, t->op, FcValueString (&value)))
+                {
                     ret = 0;
                     goto done;
+                }
+            }
+            if (op == FcOpNotEqual && t->qual == FcQualAll)
+            {
+                ret = 0;
+                if (!FamilyTableLookup (table, t->op, FcValueString (&value)))
+                {
+                    ret = values;
+                }
+                goto done;
             }
         }
 	for (v = values; v; v = FcValueListNext(v))
