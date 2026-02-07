--- generic/tclXhandles.c.orig	2014-07-30 17:35:38.000000000 +0200
+++ generic/tclXhandles.c	2014-07-30 17:35:43.000000000 +0200
@@ -567,7 +567,7 @@
 
     entryHdrPtr = HEADER_AREA (entryPtr);
     if (entryHdrPtr->freeLink != ALLOCATED_IDX)
-        panic ("Tcl_HandleFree: entry not allocated %x\n", entryHdrPtr);
+        panic ("Tcl_HandleFree: entry not allocated %p\n", entryHdrPtr);
 
     entryHdrPtr->freeLink = tblHdrPtr->freeHeadIdx;
     tblHdrPtr->freeHeadIdx =
