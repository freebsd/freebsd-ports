--- classes/include/ArtsSelectedPortTable.hh.orig	2007-11-12 16:16:29.000000000 +0100
+++ classes/include/ArtsSelectedPortTable.hh	2007-11-12 16:16:57.000000000 +0100
@@ -131,7 +131,7 @@
   //.........................................................................
   //!  Returns a reference to the ArtsPortChooser in the object.
   //-------------------------------------------------------------------------
-  ArtsPortChooser & ArtsSelectedPortTable::PortChooser() const;
+  ArtsPortChooser & PortChooser() const;
   
   //-------------------------------------------------------------------------
   //            std::vector<ArtsPortTableEntry> & PortEntries() const
