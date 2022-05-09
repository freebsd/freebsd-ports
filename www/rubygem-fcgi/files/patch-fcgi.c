--- ext/fcgi/fcgi.c.orig	2022-05-09 10:44:18 UTC
+++ ext/fcgi/fcgi.c
@@ -131,8 +131,10 @@ static VALUE fcgi_s_accept(VALUE self)
       while( *(pvalue++) != '=') size++;
       key   = rb_str_new(pkey, size);
       value = rb_str_new2(pvalue);
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
       OBJ_TAINT(key);
       OBJ_TAINT(value);
+#endif
       rb_hash_aset(data->env, key, value);
     }
 
@@ -262,7 +264,9 @@ static VALUE fcgi_stream_putc(VALUE self, VALUE ch)
   FCGX_Stream *stream;
   int c;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
   rb_secure(4);
+#endif
   Data_Get_Stream(self, stream);
   if ((c = FCGX_PutChar(NUM2INT(ch), stream)) == EOF)
     CHECK_STREAM_ERROR(stream);
@@ -274,7 +278,9 @@ static VALUE fcgi_stream_write(VALUE self, VALUE str)
   FCGX_Stream *stream;
   int len;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
   rb_secure(4);
+#endif
   Data_Get_Stream(self, stream);
   str = rb_obj_as_string(str);
   len = FCGX_PutStr(RSTRING_PTR(str), RSTRING_LEN(str), stream);
@@ -407,9 +413,11 @@ static VALUE fcgi_stream_ungetc(VALUE self, VALUE ch)
   FCGX_Stream *stream;
   int c;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
   if (rb_safe_level() >= 4 && !OBJ_TAINTED(self)) {
     rb_raise(rb_eSecurityError, "Insecure: operation on untainted IO");
   }
+#endif
   Data_Get_Stream(self, stream);
   c = FCGX_UnGetChar(NUM2INT(ch), stream);
   CHECK_STREAM_ERROR(stream);
@@ -420,11 +428,13 @@ static VALUE fcgi_stream_gets(VALUE self) {
   FCGX_Stream *stream;
   char buff[BUFSIZ];
   VALUE str = rb_str_new(0,0);
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
   OBJ_TAINT(str);
 
   if (rb_safe_level() >= 4 && !OBJ_TAINTED(self)) {
     rb_raise(rb_eSecurityError, "Insecure: operation on untainted IO");
   }
+#endif
 
   Data_Get_Stream(self, stream);
 
@@ -449,9 +459,11 @@ static VALUE fcgi_stream_read(int argc, VALUE *argv, V
   char *buff;
   int n;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
   if (rb_safe_level() >= 4 && !OBJ_TAINTED(self)) {
     rb_raise(rb_eSecurityError, "Insecure: operation on untainted IO");
   }
+#endif
 
   Data_Get_Stream(self, stream);
 
@@ -464,7 +476,9 @@ static VALUE fcgi_stream_read(int argc, VALUE *argv, V
       return  Qnil;
     }
     str = rb_str_new(buff, n);
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     OBJ_TAINT(str);
+#endif
 
     while(!FCGX_HasSeenEOF(stream)) {
       n = FCGX_GetStr(buff, 16384, stream);
@@ -488,7 +502,9 @@ static VALUE fcgi_stream_read(int argc, VALUE *argv, V
   CHECK_STREAM_ERROR(stream);
   if (n > 0) {
     str = rb_str_new(buff, n);
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     OBJ_TAINT(str);
+#endif
     free(buff);
     return str;
   }
@@ -502,9 +518,11 @@ static VALUE fcgi_stream_eof(VALUE self)
 {
   FCGX_Stream *stream;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
   if (rb_safe_level() >= 4 && !OBJ_TAINTED(self)) {
     rb_raise(rb_eSecurityError, "Insecure: operation on untainted IO");
   }
+#endif
   Data_Get_Stream(self, stream);
   return FCGX_HasSeenEOF(stream) ? Qtrue : Qfalse;
 }
@@ -513,9 +531,11 @@ static VALUE fcgi_stream_close(VALUE self)
 {
   FCGX_Stream *stream;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
   if (rb_safe_level() >= 4 && !OBJ_TAINTED(self)) {
     rb_raise(rb_eSecurityError, "Insecure: can't close");
   }
+#endif
   Data_Get_Stream(self, stream);
   if (FCGX_FClose(stream) == EOF)
     CHECK_STREAM_ERROR(stream);
@@ -532,33 +552,41 @@ static VALUE fcgi_stream_closed(VALUE self)
 
 static VALUE fcgi_stream_binmode(VALUE self)
 {
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
   if (rb_safe_level() >= 4 && !OBJ_TAINTED(self)) {
     rb_raise(rb_eSecurityError, "Insecure: operation on untainted IO");
   }
+#endif
   return self;
 }
 
 static VALUE fcgi_stream_isatty(VALUE self)
 {
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
   if (rb_safe_level() >= 4 && !OBJ_TAINTED(self)) {
     rb_raise(rb_eSecurityError, "Insecure: operation on untainted IO");
   }
+#endif
   return Qfalse;
 }
 
 static VALUE fcgi_stream_sync(VALUE self)
 {
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
   if (rb_safe_level() >= 4 && !OBJ_TAINTED(self)) {
     rb_raise(rb_eSecurityError, "Insecure: operation on untainted IO");
   }
+#endif
   return Qfalse;
 }
 
 static VALUE fcgi_stream_setsync(VALUE self,VALUE sync)
 {
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
   if (rb_safe_level() >= 4 && !OBJ_TAINTED(self)) {
     rb_raise(rb_eSecurityError, "Insecure: operation on untainted IO");
   }
+#endif
   return Qfalse;
 }
 
