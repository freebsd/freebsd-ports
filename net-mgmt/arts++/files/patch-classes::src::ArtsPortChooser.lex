--- ./classes/src/ArtsPortChooser.lex.orig	Mon Oct  2 13:05:27 2000
+++ ./classes/src/ArtsPortChooser.lex	Wed Sep 25 16:38:10 2002
@@ -233,7 +233,7 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-uint32_t ArtsPortChooser::Length(uint8_t version = 0) const
+uint32_t ArtsPortChooser::Length(uint8_t version) const
 {
   uint32_t                                length = 0;
   vector<ArtsPortChoice>::const_iterator  choiceIter;
