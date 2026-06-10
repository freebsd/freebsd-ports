--- content/browser/renderer_host/render_view_host_impl.cc.orig	2026-06-05 13:45:06 UTC
+++ content/browser/renderer_host/render_view_host_impl.cc
@@ -266,7 +266,7 @@ void RenderViewHostImpl::GetPlatformSpecificPrefs(
   GetFontInfo(gfx::win::SystemFont::kStatus, &prefs->status_font_family_name,
               &prefs->status_font_height);
 
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
   if (command_line->HasSwitch(switches::kSystemFontFamily)) {
     prefs->system_font_family_name =
