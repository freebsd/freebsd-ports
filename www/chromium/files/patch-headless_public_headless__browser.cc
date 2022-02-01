--- headless/public/headless_browser.cc.orig	2021-12-14 11:45:07 UTC
+++ headless/public/headless_browser.cc
@@ -42,7 +42,7 @@ Options::Options(int argc, const char** argv)
       user_agent(content::BuildUserAgentFromProduct(product_name_and_version)),
       window_size(kDefaultWindowSize),
       font_render_hinting(kDefaultFontRenderHinting) {
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   gl_implementation = gl::kGLImplementationANGLEName;
   angle_implementation = gl::kANGLEImplementationSwiftShaderForWebGLName;
 #endif
