--- scintilla/src/LexCaml.cxx.orig	2005-05-27 03:30:23 UTC
+++ scintilla/src/LexCaml.cxx
@@ -273,7 +273,7 @@ void ColouriseCamlDoc(
 
 		case SCE_CAML_OPERATOR: {
 			// [try to] interpret as [additional] operator char
-			char* o = 0;
+			const char* o = 0;
 			if (iscaml(ch) || isspace(ch)			/* ident or whitespace */
 				|| ((o = strchr(")]};,\'\"`#", ch)) != 0)/* "termination" chars */
 				|| !strchr("!$%&*+-./:<=>?@^|~", ch)/* "operator" chars */) {
