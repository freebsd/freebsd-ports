--- headless/public/headless_browser.cc.orig	2021-09-24 18:51:42 UTC
+++ headless/public/headless_browser.cc
@@ -42,7 +42,7 @@ Options::Options(int argc, const char** argv)
       user_agent(content::BuildUserAgentFromProduct(product_name_and_version)),
       window_size(kDefaultWindowSize),
       font_render_hinting(kDefaultFontRenderHinting) {
-#if (defined(OS_LINUX) && !defined(USE_OZONE)) || defined(OS_WIN)
+#if ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(USE_OZONE)) || defined(OS_WIN)
   gl_implementation = gl::kGLImplementationANGLEName;
   angle_implementation = gl::kANGLEImplementationSwiftShaderForWebGLName;
 #endif
