The trustlist feature, which only worked for a short period in 2003, was
removed in GpgME 2.0.0.

The gpgme_attr_t enums and their functions, which have been marked deprecated
since 2003, were removed in GpgME 2.0.0.

--- ext/gpgme/gpgme_n.c.orig	2025-06-23 05:28:53 UTC
+++ ext/gpgme/gpgme_n.c
@@ -1633,6 +1633,7 @@ rb_s_gpgme_op_card_edit_start (VALUE dummy, VALUE vctx
   return LONG2NUM(err);
 }
 
+#if defined(GPGME_VERSION_NUMBER) && GPGME_VERSION_NUMBER < 0x020000
 static VALUE
 rb_s_gpgme_op_trustlist_start (VALUE dummy, VALUE vctx, VALUE vpattern,
                                VALUE vmax_level)
@@ -1696,6 +1697,7 @@ rb_s_gpgme_op_trustlist_end (VALUE dummy, VALUE vctx)
   err = gpgme_op_trustlist_end (ctx);
   return LONG2NUM(err);
 }
+#endif
 
 static VALUE
 rb_s_gpgme_op_decrypt (VALUE dummy, VALUE vctx, VALUE vcipher, VALUE vplain)
@@ -2558,13 +2560,15 @@ Init_gpgme_n (void)
   rb_define_module_function (mGPGME, "gpgme_op_card_edit_start",
                              rb_s_gpgme_op_card_edit_start, 5);
 
-  /* Trust Item Management */
+  /* Trust Item Management removed in 2.0.0 */
+#if defined(GPGME_VERSION_NUMBER) && GPGME_VERSION_NUMBER < 0x020000
   rb_define_module_function (mGPGME, "gpgme_op_trustlist_start",
                              rb_s_gpgme_op_trustlist_start, 3);
   rb_define_module_function (mGPGME, "gpgme_op_trustlist_next",
                              rb_s_gpgme_op_trustlist_next, 2);
   rb_define_module_function (mGPGME, "gpgme_op_trustlist_end",
                              rb_s_gpgme_op_trustlist_end, 1);
+#endif
 
   /* Decrypt */
   rb_define_module_function (mGPGME, "gpgme_op_decrypt",
@@ -2805,7 +2809,8 @@ Init_gpgme_n (void)
   rb_define_const (mGPGME, "GPGME_SIG_MODE_CLEAR",
                    INT2FIX(GPGME_SIG_MODE_CLEAR));
 
-  /* gpgme_attr_t */
+  /* gpgme_attr_t removed in 2.0.0 */
+#if defined(GPGME_VERSION_NUMBER) && GPGME_VERSION_NUMBER < 0x020000
   rb_define_const (mGPGME, "GPGME_ATTR_KEYID",
                    INT2FIX(GPGME_ATTR_KEYID));
   rb_define_const (mGPGME, "GPGME_ATTR_FPR",
@@ -2868,6 +2873,7 @@ Init_gpgme_n (void)
                    INT2FIX(GPGME_ATTR_ERRTOK));
   rb_define_const (mGPGME, "GPGME_ATTR_SIG_SUMMARY",
                    INT2FIX(GPGME_ATTR_SIG_SUMMARY));
+#endif
 
   /* gpgme_validity_t */
   rb_define_const (mGPGME, "GPGME_VALIDITY_UNKNOWN",
