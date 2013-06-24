--- src/labenski/src/sheet.cpp.orig	2013-06-24 11:57:48.000000000 +0200
+++ src/labenski/src/sheet.cpp	2013-06-24 12:00:50.000000000 +0200
@@ -7098,9 +7098,9 @@
         wxPrintf(wxT("COUNT MISMATCH ERROR! \n"));
 
     for (size_t n = 0; n < wxMin(ans.GetCount(), res.GetCount()); n++)
-        if (ans[n] != res[n]) wxPrintf(wxT("Error in item %u\n"), n);
+        if (ans[n] != res[n]) wxPrintf(wxT("Error in item %zu\n"), n);
     
-    wxPrintf(msg + wxT("\n"));
+    wxPrintf("%s\n", msg.ToAscii());
 }
 
 #define CSVT1(str, a1) { wxArrayString ar; ar.Add(wxT(a1)); CSV_TEST(wxT(str), ar, ParseLine(wxT(str))); }
