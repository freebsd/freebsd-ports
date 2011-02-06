--- plugins/gssapi.c    (revision 580)
+++ plugins/gssapi.c    (working copy)
@@ -86,7 +86,7 @@

 static const char * GSSAPI_BLANK_STRING = "";

-#ifndef HAVE_GSS_C_NT_HOSTBASED_SERVICE
+#if !defined(HAVE_GSS_C_NT_HOSTBASED_SERVICE) && !defined(GSS_C_NT_HOSTBASED_SERVICE)
 extern gss_OID gss_nt_service_name;
 #define GSS_C_NT_HOSTBASED_SERVICE gss_nt_service_name
 #endif

