--- rcast_256.cc.orig	Sun May 23 15:26:24 1999
+++ rcast_256.cc	Tue Oct  8 18:46:29 2002
@@ -107,12 +107,12 @@
 }
 
 
-extern "C" EXTERN void Init_rcast_256(void){
+extern "C" void Init_rcast_256(void){
 	VALUE mCAST_256 = rb_define_module("RCAST_256");
 	
 	rb_define_const(mCAST_256, "ENCRYPT", INT2FIX(ENCRYPT) );
 	rb_define_const(mCAST_256, "DECRYPT", INT2FIX(DECRYPT) );
 
-	rb_define_module_function(mCAST_256, "set_key",(unsigned long (__cdecl *)(void)) set_key ,1);
-	rb_define_module_function(mCAST_256, "crypt_block",(unsigned long (__cdecl *)(void)) crypt_block ,3);
+	rb_define_module_function(mCAST_256, "set_key",(unsigned long (__cdecl *)(...)) set_key ,1);
+	rb_define_module_function(mCAST_256, "crypt_block",(unsigned long (__cdecl *)(...)) crypt_block ,3);
 }
