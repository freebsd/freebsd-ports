--- toolsetup.h.old	Tue Dec 17 13:25:36 2002
+++ toolsetup.h	Tue Dec 17 13:57:26 2002
@@ -23,7 +23,7 @@
 #include "toolsetupbase.h"
 #include "toolbtn.h"
 
-class ToolBarSetup : public ToolBarSetupBase
+class ToolBarSetup : ToolBarSetupBase
 {
     Q_OBJECT
 public:
