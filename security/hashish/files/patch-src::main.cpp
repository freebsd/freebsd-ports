--- src/main.cpp.orig	Sun Dec 12 21:15:50 2004
+++ src/main.cpp	Sun Dec 12 21:16:30 2004
@@ -398,9 +398,9 @@
         hashFilter = new HashFilter(*hash, new Base64Encoder(new StringSink(outstring), false));
     
     if ((m_rbox->GetSelection() == 0))
-        FileSource file1(m_filename->GetValue().c_str(), true, new Redirector(*hashFilter, false));
+        FileSource file1(m_filename->GetValue().c_str(), true, new Redirector(*hashFilter));
     else
-        StringSource string1(m_string->GetValue().c_str(), true, new Redirector(*hashFilter, false));
+        StringSource string1(m_string->GetValue().c_str(), true, new Redirector(*hashFilter));
     
     hashFilter->MessageEnd();
 
