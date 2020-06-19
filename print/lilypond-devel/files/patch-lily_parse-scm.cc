--- lily/parse-scm.cc.orig	2020-04-26 09:45:49 UTC
+++ lily/parse-scm.cc
@@ -51,6 +51,7 @@ struct Parse_start
   Parse_start (SCM form, const Input &start, bool safe, Lily_parser *parser)
     : form_ (form), start_ (start), safe_ (safe), parser_ (parser)
   {
+    parsed_.set (start.get_source_file (), start.start (), start.end ());
   }
 
   static SCM handle_error (void *data, SCM /*tag*/, SCM args)
