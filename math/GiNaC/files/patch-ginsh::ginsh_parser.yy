--- ginsh/ginsh_parser.yy.orig	Mon Feb  5 22:08:16 2007
+++ ginsh/ginsh_parser.yy	Sat Oct 20 16:46:13 2007
@@ -28,6 +28,8 @@
 
 %{
 #include "config.h"
+#include <sys/time.h>
+
 #ifdef HAVE_RUSAGE
 #include <sys/resource.h>
 #else
@@ -859,7 +861,7 @@
 		// For shell commands, revert back to filename completion
 		rl_completion_append_character = orig_completion_append_character;
 		rl_basic_word_break_characters = orig_basic_word_break_characters;
-		rl_completer_word_break_characters = GINAC_RL_COMPLETER_CAST(rl_basic_word_break_characters);
+		rl_completer_word_break_characters = GINAC_RL_COMPLETER_CAST((char*)rl_basic_word_break_characters);
 #if (GINAC_RL_VERSION_MAJOR < 4) || (GINAC_RL_VERSION_MAJOR == 4 && GINAC_RL_VERSION_MINOR < 2)
 		return completion_matches(const_cast<char *>(text), (CPFunction *)filename_completion_function);
 #else
@@ -869,7 +871,7 @@
 		// Otherwise, complete function names
 		rl_completion_append_character = '(';
 		rl_basic_word_break_characters = " \t\n\"#$%&'()*+,-./:;<=>?@[\\]^`{|}~";
-		rl_completer_word_break_characters = GINAC_RL_COMPLETER_CAST(rl_basic_word_break_characters);
+		rl_completer_word_break_characters = GINAC_RL_COMPLETER_CAST((char*)rl_basic_word_break_characters);
 #if (GINAC_RL_VERSION_MAJOR < 4) || (GINAC_RL_VERSION_MAJOR == 4 && GINAC_RL_VERSION_MINOR < 2)
 		return completion_matches(const_cast<char *>(text), (CPFunction *)fcn_generator);
 #else
@@ -892,6 +894,8 @@
 /*
  *  Main program
  */
+
+int yyparse();
 
 int main(int argc, char **argv)
 {
