--- modules/regexp-parser/tests/test_regexp_parser.c.orig	2022-06-03 13:40:39 UTC
+++ modules/regexp-parser/tests/test_regexp_parser.c
@@ -84,6 +84,9 @@ ParameterizedTestParameters(regexp_parser, test_regexp
     {.msg = "foo", .pattern = "(?<key>foo)|(?<key>bar)", .prefix=".reg.", .expected_result = TRUE, .flags = LMF_DUPNAMES, .name = ".reg.key", .value = "foo"},
     {.msg = "abc", .pattern = "Abc", .prefix="", .flags = 0, .expected_result = FALSE, .name = NULL, .value = NULL},
     {.msg = "abc", .pattern = "(?<key>Abc)", .prefix="", .flags = LMF_ICASE, .expected_result = TRUE, .name = "key", .value = "abc"},
+
+    /* store into a builtin value */
+    {.msg = "abcdef", .pattern = "(?<PID>abc)", .prefix="", .flags = 0, .expected_result = TRUE, .name = "PID", .value = "abc"},
   };
   return cr_make_param_array(RegexpParserTestParam, parser_params, G_N_ELEMENTS(parser_params));
 }
@@ -92,9 +95,10 @@ ParameterizedTest(RegexpParserTestParam *parser_param,
 {
   LogParser *p = _construct_regexp_parser(parser_param->prefix, parser_param->pattern, parser_param->flags);
   gboolean result;
+  GError *e = NULL;
 
-  result = regexp_parser_compile(p, NULL);
-  cr_assert(result, "unexpected compiling failure; pattern=%s\n", parser_param->pattern);
+  result = regexp_parser_compile(p, &e);
+  cr_assert(result, "unexpected compiling failure; pattern=%s, error=%s\n", parser_param->pattern, e->message);
 
   LogMessage *msg = log_msg_new_empty();
   log_msg_set_value(msg, LM_V_MESSAGE, parser_param->msg, -1);
