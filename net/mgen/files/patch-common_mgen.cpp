
$FreeBSD$

--- common/mgen.cpp.orig
+++ common/mgen.cpp
@@ -1319,7 +1319,7 @@
         m++;
     }
     return type; 
-};  // end Mgen::GetCmdType()
+}  // end Mgen::GetCmdType()
 
 bool Mgen::OnCommand(Mgen::Command cmd, const char* arg, bool override)
 { 
