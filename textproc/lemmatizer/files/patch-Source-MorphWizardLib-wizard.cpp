--- Source/MorphWizardLib/wizard.cpp.old	Fri Jun 17 14:37:58 2005
+++ Source/MorphWizardLib/wizard.cpp	Fri Jan 28 11:36:40 2005
@@ -35,7 +35,7 @@
 		Trim(s);
 	}
 	else
-		m_Comments.clear();
+		m_Comments.erase();
 
 	StringTokenizer Tok(s.c_str(), "%");
 	m_Flexia.clear();
