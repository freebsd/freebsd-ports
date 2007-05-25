--- pan/data/parts.cc	2007/05/19 16:09:08	286
+++ pan/data/parts.cc	2007/05/19 20:55:05	290
@@ -80,7 +80,7 @@
     register const char *k, *m;
     const StringView& key (key_mid.to_view());
 
-    const int bmax = std::min ((int)std::min (key.len, mid.len), UCHAR_MAX);
+    const int bmax = std::min ((int)std::min (key.len, mid.len), (int)UCHAR_MAX);
     k = &key.front();
     m = &mid.front();
     for (; b!=bmax; ++b)
