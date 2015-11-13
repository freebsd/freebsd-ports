--- cone/cursesmessage.C.orig	2014-01-06 19:51:56 UTC
+++ cone/cursesmessage.C
@@ -3761,10 +3761,10 @@ bool CursesMessage::decrypt(std::string 
 			gi.passphrase_fd=passphrase_fd.c_str();
 		}
 
-		gi.input_func= &tempSaveText.input_func;
+		gi.input_func= &CursesMessage::DecryptSaveText::input_func;
 		gi.input_func_arg= &tempSaveText;
 
-		gi.output_func= &tempSaveText.output_func;
+		gi.output_func= &CursesMessage::DecryptSaveText::output_func; 
 		gi.output_func_arg= &tempSaveText;
 
 		gi.errhandler_func= &tempSaveText.err_func;
