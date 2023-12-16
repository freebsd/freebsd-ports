--- src/3rdparty/chromium/ui/ozone/platform/wayland/host/xdg_toplevel_wrapper_impl.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/ui/ozone/platform/wayland/host/xdg_toplevel_wrapper_impl.cc
@@ -272,7 +272,7 @@ void XDGToplevelWrapperImpl::ConfigureTopLevel(
           CheckIfWlArrayHasValue(states, XDG_TOPLEVEL_STATE_ACTIVATED),
   };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   if (xdg_toplevel_get_version(xdg_toplevel) >=
       XDG_TOPLEVEL_STATE_TILED_LEFT_SINCE_VERSION) {
     // All four tiled states have the same since version, so it is enough to
