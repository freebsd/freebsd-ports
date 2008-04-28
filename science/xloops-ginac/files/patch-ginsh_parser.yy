--- ginsh/ginsh_parser.yy.orig	2001-11-01 00:46:50.000000000 +0900
+++ ginsh/ginsh_parser.yy	2008-04-09 21:35:18.000000000 +0900
@@ -29,6 +29,7 @@
 %{
 #include "config.h"
 
+#include <sys/time.h>
 #include <sys/resource.h>
 
 #if HAVE_UNISTD_H
@@ -50,6 +51,12 @@
 static const char *orig_basic_word_break_characters;
 #endif
 
+#if (GINAC_RL_VERSION_MAJOR >= 5)
+#define GINAC_RL_COMPLETER_CAST(a) const_cast<char *>((a))
+#else
+#define GINAC_RL_COMPLETER_CAST(a) (a)
+#endif
+
 // Expression stack for ", "" and """
 static void push(const ex &e);
 static ex exstack[3];
@@ -625,7 +632,8 @@
 }
 
 // All registered GiNaC functions
-void GiNaC::ginsh_get_ginac_functions(void)
+namespace GiNaC {
+void ginsh_get_ginac_functions(void)
 {
 	vector<function_options>::const_iterator i = function::registered_functions().begin(), end = function::registered_functions().end();
 	unsigned serial = 0;
@@ -635,6 +643,7 @@
 		serial++;
 	}
 }
+}
 
 
 /*
@@ -764,7 +773,7 @@
 		// For shell commands, revert back to filename completion
 		rl_completion_append_character = orig_completion_append_character;
 		rl_basic_word_break_characters = orig_basic_word_break_characters;
-		rl_completer_word_break_characters = rl_basic_word_break_characters;
+		rl_completer_word_break_characters = GINAC_RL_COMPLETER_CAST(rl_basic_word_break_characters);
 #if (GINAC_RL_VERSION_MAJOR < 4) || (GINAC_RL_VERSION_MAJOR == 4 && GINAC_RL_VERSION_MINOR < 2)
 		return completion_matches(const_cast<char *>(text), (CPFunction *)filename_completion_function);
 #else
@@ -774,7 +783,7 @@
 		// Otherwise, complete function names
 		rl_completion_append_character = '(';
 		rl_basic_word_break_characters = " \t\n\"#$%&'()*+,-./:;<=>?@[\\]^`{|}~";
-		rl_completer_word_break_characters = rl_basic_word_break_characters;
+		rl_completer_word_break_characters = GINAC_RL_COMPLETER_CAST(rl_basic_word_break_characters);
 #if (GINAC_RL_VERSION_MAJOR < 4) || (GINAC_RL_VERSION_MAJOR == 4 && GINAC_RL_VERSION_MINOR < 2)
 		return completion_matches(const_cast<char *>(text), (CPFunction *)fcn_generator);
 #else
@@ -797,6 +806,8 @@
  *  Main program
  */
 
+int yyparse();
+
 int main(int argc, char **argv)
 {
 	// Print banner in interactive mode
