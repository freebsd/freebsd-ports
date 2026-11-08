-- ftxui-7.x compatibility

--- app/mon/mon_tui/src/tui/view/component/focus_manager.hpp.orig	2026-10-08 06:09:54 UTC
+++ app/mon/mon_tui/src/tui/view/component/focus_manager.hpp
@@ -46,15 +46,15 @@ class ContainerBase : public ComponentBase {
   }
 
   Component ActiveChild() override {
-    if (children_.size() == 0)
+    if (children().size() == 0)
       return nullptr;
 
-    return children_[*selector_ % children_.size()];
+    return children()[*selector_ % children().size()];
   }
 
   void SetActiveChild(ComponentBase* child) override {
-    for (size_t i = 0; i < children_.size(); ++i) {
-      if (children_[i].get() == child) {
+    for (size_t i = 0; i < children().size(); ++i) {
+      if (children()[i].get() == child) {
         *selector_ = static_cast<int>(i);
         return;
       }
@@ -73,18 +73,18 @@ class ContainerBase : public ComponentBase {
   int* selector_ = nullptr;
 
   void MoveSelector(int dir) {
-    for (int i = *selector_ + dir; i >= 0 && i < (int)children_.size();
+    for (int i = *selector_ + dir; i >= 0 && i < (int)children().size();
          i += dir) {
-      if (children_[i]->Focusable()) {
+      if (children()[i]->Focusable()) {
         *selector_ = i;
         return;
       }
     }
   }
   void MoveSelectorWrap(int dir) {
-    for (size_t offset = 1; offset < children_.size(); ++offset) {
-      size_t i = (*selector_ + offset * dir + children_.size()) % children_.size();
-      if (children_[i]->Focusable()) {
+    for (size_t offset = 1; offset < children().size(); ++offset) {
+      size_t i = (*selector_ + offset * dir + children().size()) % children().size();
+      if (children()[i]->Focusable()) {
         *selector_ = static_cast<int>(i);
         return;
       }
@@ -102,7 +102,7 @@ class FocusManager : public ftxui::ContainerBase
   {
     using namespace ftxui;
     Elements elements;
-    for (auto& it : children_)
+    for (auto& it : children())
       elements.push_back(it->Render());
     if (elements.size() == 0)
       return text("Empty container");
@@ -112,12 +112,12 @@ class FocusManager : public ftxui::ContainerBase
   bool EventHandler(ftxui::Event event) override {
     using namespace ftxui;
     int old_selected = *selector_;
-    if (event == Event::Tab && children_.size())
+    if (event == Event::Tab && children().size())
       MoveSelectorWrap(+1);
-    if (event == Event::TabReverse && children_.size())
+    if (event == Event::TabReverse && children().size())
       MoveSelectorWrap(-1);
 
-    *selector_ = std::max(0, std::min(int(children_.size()) - 1, *selector_));
+    *selector_ = std::max(0, std::min(int(children().size()) - 1, *selector_));
     return old_selected != *selector_;
   }
 };
