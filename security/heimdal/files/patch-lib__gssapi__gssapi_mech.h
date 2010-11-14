--- lib/gssapi/gssapi_mech.h.orig	2010-09-13 09:23:34.000000000 +0200
+++ lib/gssapi/gssapi_mech.h	2010-11-05 11:04:11.000000000 +0100
@@ -353,6 +353,12 @@
 		   gss_buffer_t cred_token,
 		   gss_cred_id_t * cred_handle);
 
+typedef OM_uint32 GSSAPI_CALLCONV
+_gss_pname_to_uid (OM_uint32 * minor_status,		/* minor status */
+	       gss_name_t pname,	/* principal name */
+	       gss_OID mech,		/* mechanism to query */
+	       uid_t *uidp		/* pointer to UID for result */
+	      );
 
 #define GMI_VERSION 2
 
@@ -405,6 +411,7 @@
 	_gss_store_cred_t		*gm_store_cred;
 	_gss_export_cred_t		*gm_export_cred;
 	_gss_import_cred_t		*gm_import_cred;
+	_gss_pname_to_uid		*gm_pname_to_uid;
 } gssapi_mech_interface_desc, *gssapi_mech_interface;
 
 gssapi_mech_interface
