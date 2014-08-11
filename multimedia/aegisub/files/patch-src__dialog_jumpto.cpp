--- src/dialog_jumpto.cpp.orig	2014-07-28 23:29:16.000000000 +0900
+++ src/dialog_jumpto.cpp	2014-08-05 21:03:34.000000000 +0900
@@ -43,6 +43,13 @@
 #include <wx/stattext.h>
 #include <wx/textctrl.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 namespace {
 struct DialogJumpTo {
 	wxDialog d;
@@ -74,7 +81,7 @@
 	auto LabelTime = new wxStaticText(&d, -1, _("Time: "));
 
 	JumpFrame = new wxTextCtrl(&d,-1,"",wxDefaultPosition,wxSize(-1,-1),wxTE_PROCESS_ENTER, IntValidator((int)jumpframe));
-	JumpFrame->SetMaxLength(std::to_string(c->project->VideoProvider()->GetFrameCount() - 1).size());
+	JumpFrame->SetMaxLength(TO_STRING(c->project->VideoProvider()->GetFrameCount() - 1).size());
 	JumpTime = new TimeEdit(&d, -1, c, agi::Time(c->videoController->TimeAtFrame(jumpframe)).GetAssFormatted(), wxSize(-1,-1));
 
 	auto TimesSizer = new wxGridSizer(2, 5, 5);
