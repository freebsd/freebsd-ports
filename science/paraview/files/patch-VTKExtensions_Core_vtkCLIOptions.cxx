--- VTKExtensions/Core/vtkCLIOptions.cxx.orig	2024-12-29 23:38:49 UTC
+++ VTKExtensions/Core/vtkCLIOptions.cxx
@@ -52,10 +52,17 @@ class PVFormatter : public CLI::Formatter (public)
 
 public:
   // overridden to add a new line before each group.
+#if (CLI11_VERSION_MAJOR > 2 || (CLI11_VERSION_MAJOR == 2 && CLI11_VERSION_MINOR >= 5))
+  std::string make_expanded(const CLI::App* sub, CLI::AppFormatMode mode) const override
+  {
+    return "\n" + Superclass::make_expanded(sub, mode);
+  }
+#else
   std::string make_expanded(const CLI::App* sub) const override
   {
     return "\n" + Superclass::make_expanded(sub);
   }
+#endif
 
   // overridden to ensure good word wrapping for description text.
   std::string make_option_desc(const CLI::Option* option) const override
