--- source/components/namespace/nsaccess.c.orig	2024-08-27 21:14:58 UTC
+++ source/components/namespace/nsaccess.c
@@ -449,7 +449,9 @@ AcpiNsLookup (
     ACPI_NAMESPACE_NODE     *CurrentNode = NULL;
     ACPI_NAMESPACE_NODE     *ThisNode = NULL;
     UINT32                  NumSegments;
+#ifdef ACPI_DEBUG_OUTPUT
     UINT32                  NumCarats;
+#endif
     ACPI_NAME               SimpleName;
     ACPI_OBJECT_TYPE        TypeToCheckFor;
     ACPI_OBJECT_TYPE        ThisSearchType;
@@ -573,7 +575,9 @@ AcpiNsLookup (
              * the parent node for each prefix instance.
              */
             ThisNode = PrefixNode;
+#ifdef ACPI_DEBUG_OUTPUT
             NumCarats = 0;
+#endif
             while (*Path == (UINT8) AML_PARENT_PREFIX)
             {
                 /* Name is fully qualified, no search rules apply */
@@ -588,7 +592,9 @@ AcpiNsLookup (
 
                 /* Backup to the parent node */
 
+#ifdef ACPI_DEBUG_OUTPUT
                 NumCarats++;
+#endif
                 ThisNode = ThisNode->Parent;
                 if (!ThisNode)
                 {
@@ -611,12 +617,14 @@ AcpiNsLookup (
                 }
             }
 
+#ifdef ACPI_DEBUG_OUTPUT
             if (SearchParentFlag == ACPI_NS_NO_UPSEARCH)
             {
                 ACPI_DEBUG_PRINT ((ACPI_DB_NAMES,
                     "Search scope is [%4.4s], path has %u carat(s)\n",
                     AcpiUtGetNodeName (ThisNode), NumCarats));
             }
+#endif
         }
 
         /*
