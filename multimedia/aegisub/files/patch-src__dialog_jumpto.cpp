--- src/dialog_jumpto.cpp.orig
+++ src/dialog_jumpto.cpp
@@ -48,6 +48,13 @@
 #include <wx/stattext.h>
 #include <wx/textctrl.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 DialogJumpTo::DialogJumpTo(agi::Context *c)
 : wxDialog(c->parent, -1, _("Jump to"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxWANTS_CHARS)
 , c(c)
@@ -59,7 +66,7 @@
 	auto LabelTime = new wxStaticText(this, -1, _("Time: "));
 
 	JumpFrame = new wxTextCtrl(this,-1,"",wxDefaultPosition,wxSize(-1,-1),wxTE_PROCESS_ENTER, IntValidator((int)jumpframe));
-	JumpFrame->SetMaxLength(std::to_string(c->videoController->GetLength() - 1).size());
+	JumpFrame->SetMaxLength(TO_STRING(c->videoController->GetLength() - 1).size());
 	JumpTime = new TimeEdit(this, -1, c, AssTime(c->videoController->TimeAtFrame(jumpframe)).GetAssFormated(), wxSize(-1,-1));
 
 	auto TimesSizer = new wxGridSizer(2, 5, 5);
