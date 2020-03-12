--- src/lib/STOFFSpreadsheetListener.hxx.orig	2018-04-25 09:25:45 UTC
+++ src/lib/STOFFSpreadsheetListener.hxx
@@ -61,7 +61,7 @@ struct State;
 }
 
 /** This class contents the main functions needed to create a spreadsheet processing Document */
-class STOFFSpreadsheetListener : public STOFFListener
+class STOFFSpreadsheetListener final : public STOFFListener
 {
 public:
   /** constructor */
