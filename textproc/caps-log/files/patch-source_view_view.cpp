-- ftxui-7.x compatibility

--- source/view/view.cpp.orig	2026-10-08 03:44:47 UTC
+++ source/view/view.cpp
@@ -92,8 +92,12 @@ class PopUpViewLayoutWrapper : public PopUpViewBase, p
         });
 
         auto helpRenderer = Renderer(closeHelpButton, [closeHelpButton, this]() {
-            return vbox(markdown(m_message), separator(), closeHelpButton->Render() | center) |
-                   center | border;
+            auto help_elements = markdown(m_message);
+            help_elements.push_back(separator());
+            help_elements.push_back(closeHelpButton->Render() | center);
+
+            return vbox(std::move(help_elements)) |
+                       center | border;
         });
 
         Components comps{m_view->getAnnualViewLayout()->getComponent(),
