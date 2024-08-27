--- ui/views/widget/root_view.cc.orig	2024-08-26 12:06:38 UTC
+++ ui/views/widget/root_view.cc
@@ -129,7 +129,7 @@ class AnnounceTextView : public View {
 #if BUILDFLAG(IS_CHROMEOS)
     // On ChromeOS, kAlert role can invoke an unnecessary event on reparenting.
     node_data->role = ax::mojom::Role::kStaticText;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/40658933): Use live regions (do not use alerts).
     // May require setting kLiveStatus, kContainerLiveStatus to "polite".
     node_data->role = ax::mojom::Role::kAlert;
