--- src/grid_column.cpp.orig	2014-08-05 23:58:58.000000000 +0900
+++ src/grid_column.cpp	2014-08-06 00:01:32.000000000 +0900
@@ -27,6 +27,13 @@
 
 #include <wx/dc.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_WSTRING(x) std::to_wstring(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_WSTRING(x) boost::lexical_cast<std::wstring>(x)
+#endif
+
 int WidthHelper::operator()(boost::flyweight<std::string> const& str) {
 	if (str.get().empty()) return 0;
 	auto it = widths.find(str);
@@ -84,7 +91,7 @@
 	bool Centered() const override { return true; }
 
 	wxString Value(const AssDialogue *d, const agi::Context * = nullptr) const override {
-		return std::to_wstring(d->Row + 1);
+		return TO_WSTRING(d->Row + 1);
 	}
 
 	int Width(const agi::Context *c, WidthHelper &helper) const override {
@@ -108,12 +115,12 @@
 	bool Centered() const override { return true; }
 
 	wxString Value(const AssDialogue *d, const agi::Context *) const override {
-		return d->Layer ? wxString(std::to_wstring(d->Layer)) : wxString();
+		return d->Layer ? wxString(TO_WSTRING(d->Layer)) : wxString();
 	}
 
 	int Width(const agi::Context *c, WidthHelper &helper) const override {
 		int max_layer = max_value(&AssDialogue::Layer, c->ass->Events);
-		return max_layer == 0 ? 0 : helper(std::to_wstring(max_layer));
+		return max_layer == 0 ? 0 : helper(TO_WSTRING(max_layer));
 	}
 };
 
@@ -130,7 +137,7 @@
 
 	wxString Value(const AssDialogue *d, const agi::Context *c) const override {
 		if (by_frame)
-			return std::to_wstring(c->videoController->FrameAtTime(d->Start, agi::vfr::START));
+			return TO_WSTRING(c->videoController->FrameAtTime(d->Start, agi::vfr::START));
 		return to_wx(d->Start.GetAssFormatted());
 	}
 
@@ -138,7 +145,7 @@
 		if (!by_frame)
 			return helper(wxS("0:00:00.00"));
 		int frame = c->videoController->FrameAtTime(max_value(&AssDialogue::Start, c->ass->Events), agi::vfr::START);
-		return helper(std::to_wstring(frame));
+		return helper(TO_WSTRING(frame));
 	}
 };
 
@@ -148,7 +155,7 @@
 
 	wxString Value(const AssDialogue *d, const agi::Context *c) const override {
 		if (by_frame)
-			return std::to_wstring(c->videoController->FrameAtTime(d->End, agi::vfr::END));
+			return TO_WSTRING(c->videoController->FrameAtTime(d->End, agi::vfr::END));
 		return to_wx(d->End.GetAssFormatted());
 	}
 
@@ -156,7 +163,7 @@
 		if (!by_frame)
 			return helper(wxS("0:00:00.00"));
 		int frame = c->videoController->FrameAtTime(max_value(&AssDialogue::End, c->ass->Events), agi::vfr::END);
-		return helper(std::to_wstring(frame));
+		return helper(TO_WSTRING(frame));
 	}
 };
 
@@ -220,7 +227,7 @@
 	bool Centered() const override { return true; }
 
 	wxString Value(const AssDialogue *d, const agi::Context *) const override {
-		return d->Margin[Index] ? wxString(std::to_wstring(d->Margin[Index])) : wxString();
+		return d->Margin[Index] ? wxString(TO_WSTRING(d->Margin[Index])) : wxString();
 	}
 
 	int Width(const agi::Context *c, WidthHelper &helper) const override {
@@ -229,7 +236,7 @@
 			if (line.Margin[Index] > max)
 				max = line.Margin[Index];
 		}
-		return max == 0 ? 0 : helper(std::to_wstring(max));
+		return max == 0 ? 0 : helper(TO_WSTRING(max));
 	}
 };
 
@@ -296,7 +303,7 @@
 		int cps = CPS(d);
 		if (cps < 0 || cps > 100) return;
 
-		wxString str = std::to_wstring(cps);
+		wxString str = TO_WSTRING(cps);
 		wxSize ext = dc.GetTextExtent(str);
 		auto tc = dc.GetTextForeground();
 
