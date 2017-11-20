--- src/ui/wxWidgets/passwordsubset.cpp.orig	2017-11-20 03:11:40.369984000 +0300
+++ src/ui/wxWidgets/passwordsubset.cpp	2017-11-20 03:12:19.012627000 +0300
@@ -240,7 +240,7 @@
       m_vals->Clear();
       m_error->SetLabel(wxEmptyString);
       
-      std::wistringstream is(pos_str.wc_str());
+      std::wistringstream is(static_cast<const wchar_t*>(pos_str.wc_str()));
       int pos;
       while (is >> pos) {
 	if (pos > 0 && pos <= N)
@@ -280,7 +280,7 @@
     wxASSERT(val_str.length() % 2 == 0);
     for (size_t i = 0; i < val_str.length(); i += 2)
       reduced_str += val_str[i];
-    PWSclipboard::GetInstance()->SetData(reduced_str.wc_str());
+    PWSclipboard::GetInstance()->SetData(static_cast<const wchar_t*>(reduced_str.wc_str()));
   }
 }
 
