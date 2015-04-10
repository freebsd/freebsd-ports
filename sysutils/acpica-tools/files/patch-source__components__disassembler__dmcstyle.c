--- ../../source/components/disassembler/dmcstyle.c.orig	2015-04-08 13:17:53.000000000 -0400
+++ ../../source/components/disassembler/dmcstyle.c	2015-04-10 00:55:46.808791000 -0400
@@ -114,20 +114,12 @@
     Child1 = AcpiPsGetArg (Op, 0);
     if (!Child1)
     {
-        /* Parse tree may be confused or corrupted */
-
         return (FALSE);
     }
 
     /* Get the second operand */
 
     Child2 = Child1->Common.Next;
-    if (!Child2)
-    {
-        /* Parse tree may be confused or corrupted */
-
-        return (FALSE);
-    }
 
     /* Setup the operator string for this opcode */
 
@@ -307,16 +299,8 @@
         /* Target is 3rd operand */
 
         Target = Child2->Common.Next;
-
         if (Op->Common.AmlOpcode == AML_DIVIDE_OP)
         {
-            if (!Target)
-            {
-                /* Parse tree may be confused or corrupted */
-
-                return (FALSE);
-            }
-
             /*
              * Divide has an extra target operand (Remainder).
              * If this extra target is specified, it cannot be converted
@@ -419,13 +403,6 @@
         /* Target is optional, 3rd operand */
 
         Target = Child2->Common.Next;
-        if (!Target)
-        {
-            /* Parse tree may be confused or corrupted */
-
-            return (FALSE);
-        }
-
         if (AcpiDmIsValidTarget (Target))
         {
             AcpiDmPromoteTarget (Op, Target);
@@ -446,13 +423,6 @@
          * source so that the target is processed first.
          */
         Target = Child1->Common.Next;
-        if (!Target)
-        {
-            /* Parse tree may be confused or corrupted */
-
-            return (FALSE);
-        }
-
         AcpiDmPromoteTarget (Op, Target);
 
         if (!Target->Common.OperatorSymbol)
