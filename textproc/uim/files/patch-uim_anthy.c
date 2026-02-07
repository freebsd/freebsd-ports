--- uim/anthy.c.orig	2017-08-14 00:07:27 UTC
+++ uim/anthy.c
@@ -40,6 +40,7 @@
 #include "uim.h"
 #include "uim-scm.h"
 #include "uim-scm-abbrev.h"
+#include "uim-util.h"
 #include "dynlib.h"
 
 
@@ -51,6 +52,9 @@ void uim_anthy_plugin_instance_quit(void);
 static uim_bool initialized;
 static uim_lisp context_list;
 
+static void *iconv_cd_e2u;
+static void *iconv_cd_u2e;
+
 static void
 validate_segment_index(anthy_context_t ac, int i)
 {
@@ -96,15 +100,26 @@ init_anthy_lib(void)
 }
 
 static uim_lisp
-create_context(void)
+create_context(uim_lisp encoding_)
 {
   anthy_context_t ac;
   uim_lisp ac_;
+  int encoding;
 
+  /* 0: compiled, 1: EUC-JP, 2: UTF-8 */
+  encoding = C_INT(encoding_);
+
+  if (!iconv_cd_e2u)
+    iconv_cd_e2u = uim_iconv->create("UTF-8", "EUC-JP");
+
+  if (!iconv_cd_u2e)
+    iconv_cd_u2e = uim_iconv->create("EUC-JP", "UTF-8");
+ 
   ac = anthy_create_context();
   if (!ac)
     uim_fatal_error("anthy_create_context() failed");
 
+  anthy_context_set_encoding(ac, encoding);
   ac_ = MAKE_PTR(ac);
   context_list = uim_scm_callf("cons", "oo", ac_, context_list);
 
@@ -338,6 +353,42 @@ commit_nth_prediction(uim_lisp ac_, uim_lisp nth_)
 #endif
 }
 
+static uim_lisp
+eucjp_to_utf8(uim_lisp str_)
+{
+  const char *str;
+  char *convstr;
+  uim_lisp utf8_;
+
+  if (!iconv_cd_e2u)
+    return MAKE_STR("〓");
+
+  str = REFER_C_STR(str_);
+  convstr = uim_iconv->convert(iconv_cd_e2u, str);
+  utf8_ = MAKE_STR(convstr);
+  free(convstr);
+
+  return utf8_;
+}
+
+static uim_lisp
+utf8_to_eucjp(uim_lisp str_)
+{
+  const char *str;
+  char *convstr;
+  uim_lisp eucjp_;
+
+  if (!iconv_cd_u2e)
+    return MAKE_STR("");
+
+  str = REFER_C_STR(str_);
+  convstr = uim_iconv->convert(iconv_cd_u2e, str);
+  eucjp_ = MAKE_STR(convstr);
+  free(convstr);
+
+  return eucjp_;
+}
+
 #ifndef ENABLE_ANTHY_STATIC
 void
 uim_plugin_instance_init(void)
@@ -352,7 +403,7 @@ uim_anthy_plugin_instance_init(void)
   uim_scm_eval_c_string("(require-extension (srfi 1))"); /* for delete! */
 
   uim_scm_init_proc0("anthy-lib-init", init_anthy_lib);
-  uim_scm_init_proc0("anthy-lib-alloc-context", create_context);
+  uim_scm_init_proc1("anthy-lib-alloc-context", create_context);
   uim_scm_init_proc1("anthy-lib-free-context", release_context);
   uim_scm_init_proc2("anthy-lib-set-string", set_string);
   uim_scm_init_proc1("anthy-lib-get-nr-segments",get_nr_segments);
@@ -368,6 +419,8 @@ uim_anthy_plugin_instance_init(void)
   uim_scm_init_proc2("anthy-lib-get-nth-prediction", get_nth_prediction);
   uim_scm_init_proc2("anthy-lib-commit-nth-prediction",
 		     commit_nth_prediction);
+  uim_scm_init_proc1("anthy-lib-eucjp-to-utf8", eucjp_to_utf8);
+  uim_scm_init_proc1("anthy-lib-utf8-to-eucjp", utf8_to_eucjp);
 }
 
 #ifndef ENABLE_ANTHY_STATIC
@@ -385,5 +438,14 @@ uim_anthy_plugin_instance_quit(void)
 
     anthy_quit();
     initialized = UIM_FALSE;
+
+    if (iconv_cd_e2u) {
+      uim_iconv->release(iconv_cd_e2u);
+      iconv_cd_e2u = NULL;
+    }
+    if (iconv_cd_u2e) {
+      uim_iconv->release(iconv_cd_u2e);
+      iconv_cd_u2e = NULL;
+    }
   }
 }
