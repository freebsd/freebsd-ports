--- lib/gssapi/gssapi/gssapi.h.orig	2010-11-05 10:44:14.000000000 +0100
+++ lib/gssapi/gssapi/gssapi.h	2010-11-05 10:51:26.000000000 +0100
@@ -929,6 +929,14 @@
 		gss_buffer_t /* cred_token */,
 		gss_cred_id_t * /* cred_handle */);
 
+#ifdef _UID_T_DECLARED
+GSSAPI_LIB_FUNCTION OM_uint32 GSSAPI_LIB_CALL
+gss_pname_to_uid
+		(OM_uint32 * /* minor status */,
+		 const gss_name_t /* principal name */,
+		 const gss_OID mech /* mechanism to query */,
+		 uid_t * /* pointer to UID for result */);
+#endif
 
 GSSAPI_CPP_END
 
