--- src/base_grid.cpp.orig
+++ src/base_grid.cpp
@@ -67,6 +67,15 @@
 #include <wx/scrolbar.h>
 #include <wx/sizer.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x) 
+#define TO_WSTRING(x) std::to_wstring(x) 
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#define TO_WSTRING(x) boost::lexical_cast<std::wstring>(x)
+#endif
+
 enum {
 	GRID_SCROLLBAR = 1730,
 	MENU_SHOW_COL = 1250 // Needs 15 IDs after this
@@ -194,8 +203,8 @@
 }
 
 void BaseGrid::OnSubtitlesSave() {
-	context->ass->SaveUIState("Scroll Position", std::to_string(yPos));
-	context->ass->SaveUIState("Active Line", std::to_string(GetDialogueIndex(active_line)));
+	context->ass->SaveUIState("Scroll Position", TO_STRING(yPos));
+	context->ass->SaveUIState("Active Line", TO_STRING(GetDialogueIndex(active_line)));
 }
 
 void BaseGrid::OnShowColMenu(wxCommandEvent &event) {
@@ -557,11 +566,11 @@
 }
 
 void BaseGrid::GetRowStrings(int row, AssDialogue *line, bool *paint_columns, wxString *strings, bool replace, wxString const& rep_char) const {
-	if (paint_columns[0]) strings[0] = std::to_wstring(row + 1);
-	if (paint_columns[1]) strings[1] = std::to_wstring(line->Layer);
+	if (paint_columns[0]) strings[0] = TO_WSTRING(row + 1);
+	if (paint_columns[1]) strings[1] = TO_WSTRING(line->Layer);
 	if (byFrame) {
-		if (paint_columns[2]) strings[2] = std::to_wstring(context->videoController->FrameAtTime(line->Start, agi::vfr::START));
-		if (paint_columns[3]) strings[3] = std::to_wstring(context->videoController->FrameAtTime(line->End, agi::vfr::END));
+		if (paint_columns[2]) strings[2] = TO_WSTRING(context->videoController->FrameAtTime(line->Start, agi::vfr::START));
+		if (paint_columns[3]) strings[3] = TO_WSTRING(context->videoController->FrameAtTime(line->End, agi::vfr::END));
 	}
 	else {
 		if (paint_columns[2]) strings[2] = to_wx(line->Start.GetAssFormated());
@@ -570,9 +579,9 @@
 	if (paint_columns[4]) strings[4] = to_wx(line->Style);
 	if (paint_columns[5]) strings[5] = to_wx(line->Actor);
 	if (paint_columns[6]) strings[6] = to_wx(line->Effect);
-	if (paint_columns[7]) strings[7] = line->Margin[0] ? wxString(std::to_wstring(line->Margin[0])) : wxString();
-	if (paint_columns[8]) strings[8] = line->Margin[1] ? wxString(std::to_wstring(line->Margin[1])) : wxString();
-	if (paint_columns[9]) strings[9] = line->Margin[2] ? wxString(std::to_wstring(line->Margin[2])) : wxString();
+	if (paint_columns[7]) strings[7] = line->Margin[0] ? wxString(TO_WSTRING(line->Margin[0])) : wxString();
+	if (paint_columns[8]) strings[8] = line->Margin[1] ? wxString(TO_WSTRING(line->Margin[1])) : wxString();
+	if (paint_columns[9]) strings[9] = line->Margin[2] ? wxString(TO_WSTRING(line->Margin[2])) : wxString();
 
 	if (paint_columns[10]) {
 		strings[10].clear();
@@ -799,7 +808,7 @@
 	// O(1) widths
 	int marginLen = dc.GetTextExtent("0000").GetWidth();
 
-	int labelLen = dc.GetTextExtent(std::to_wstring(GetRows())).GetWidth();
+	int labelLen = dc.GetTextExtent(TO_WSTRING(GetRows())).GetWidth();
 	int startLen = 0;
 	int endLen = 0;
 	if (!byFrame)
@@ -844,12 +853,12 @@
 	}
 
 	// Finish layer
-	int layerLen = maxLayer ? dc.GetTextExtent(std::to_wstring(maxLayer)).GetWidth() : 0;
+	int layerLen = maxLayer ? dc.GetTextExtent(TO_WSTRING(maxLayer)).GetWidth() : 0;
 
 	// Finish times
 	if (byFrame) {
-		startLen = dc.GetTextExtent(std::to_wstring(maxStart)).GetWidth();
-		endLen = dc.GetTextExtent(std::to_wstring(maxEnd)).GetWidth();
+		startLen = dc.GetTextExtent(TO_WSTRING(maxStart)).GetWidth();
+		endLen = dc.GetTextExtent(TO_WSTRING(maxEnd)).GetWidth();
 	}
 
 	// Set column widths
