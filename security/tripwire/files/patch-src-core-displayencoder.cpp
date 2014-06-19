--- src/core/displayencoder.cpp.orig	2011-11-21 17:06:56.000000000 +0100
+++ src/core/displayencoder.cpp	2014-06-15 01:46:55.000000000 +0200
@@ -825,11 +825,10 @@ bool cEncoder::OnlyOneCatagoryPerChar() 
         {
             bool fFailedATest = false;
 
-            ach[0] = ch;
+            TSTRING ach(1, ch);
             for( sack_type::const_iterator atE = m_encodings.begin(); atE != m_encodings.end(); atE++ )
             {
-		TSTRING::const_iterator first(&ach[0]), last(&ach[1]);
-                if( (*atE)->NeedsEncoding( first, last ) )
+                if( (*atE)->NeedsEncoding( ach.begin(), ach.end() ) )
                 {
                     if( fFailedATest )
                         return false; // each char can only fail one test
