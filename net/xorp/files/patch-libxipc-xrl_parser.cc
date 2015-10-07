--- libxipc/xrl_parser.cc.orig	2012-01-11 17:56:10 UTC
+++ libxipc/xrl_parser.cc
@@ -105,18 +105,6 @@ XrlParseError::pretty_print(const size_t
 	+ _reason + string("\n") + snapshot + string("\n") + indicator;
 }
 
-// ----------------------------------------------------------------------------
-// Utility routines for Xrl parsing
-
-static inline void
-advance_to_either(const string& input, string::const_iterator& sci,
-		  const char* choices) {
-    while (sci != input.end()) {
-	if (strchr(choices,*sci)) break;
-	sci++;
-    }
-}
-
 static inline void
 advance_to_char(const string& input, string::const_iterator& sci, char c)
 {
@@ -132,16 +120,6 @@ isxrlplain(int c)
     return (xorp_isalnum(c) || c == '_' || c == '-');
 }
 
-static inline size_t
-skip_xrl_plain_chars(const string& input, string::const_iterator& sci)
-{
-    string::const_iterator start = sci;
-    for ( ; sci != input.end() && isxrlplain(*sci); sci++) {
-	// XXX: Empty body
-    }
-    return sci - start;
-}
-
 static inline char
 c_escape_to_char(const string& input,
 		 string::const_iterator sci) {
@@ -238,12 +216,6 @@ skip_past_blanks(const string& s, string
 }
 
 static inline void
-skip_one_char(const string&, string::const_iterator* sci)
-{
-    sci++;
-}
-
-static inline void
 skip_cplusplus_comments(const string& s, string::const_iterator& sci)
 {
     assert(*sci == '/');
@@ -367,20 +339,6 @@ get_unquoted_value(const string& input,
     token = string(sci_start, sci);
 }
 
-static inline string::const_iterator
-uninterrupted_token_end(const string& input,
-			string::const_iterator& sci)
-{
-    string::const_iterator end = sci;
-
-    while (end != input.end() &&
-	  ( !xorp_isspace(*end) && isascii(*end) && !xorp_iscntrl(*end) )) {
-	end++;
-    }
-
-    return end;
-}
-
 static inline void
 get_protocol_target_and_command(const string& input,
 				string::const_iterator& sci,
