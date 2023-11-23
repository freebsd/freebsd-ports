--- ui/gfx/x/xlib_support.cc.orig	2023-11-22 14:00:11 UTC
+++ ui/gfx/x/xlib_support.cc
@@ -39,10 +39,18 @@ void InitXlib() {
     return;
   }
 
+#if BUILDFLAG(IS_BSD)
+  DUMP_WILL_BE_CHECK(xlib_loader->Load("libX11.so"));
+#else
   DUMP_WILL_BE_CHECK(xlib_loader->Load("libX11.so.6"));
+#endif
 
   auto* xlib_xcb_loader = GetXlibXcbLoader();
+#if BUILDFLAG(IS_BSD)
+  DUMP_WILL_BE_CHECK(xlib_xcb_loader->Load("libX11-xcb.so"));
+#else
   DUMP_WILL_BE_CHECK(xlib_xcb_loader->Load("libX11-xcb.so.1"));
+#endif
 
   DUMP_WILL_BE_CHECK(xlib_loader->XInitThreads());
 
