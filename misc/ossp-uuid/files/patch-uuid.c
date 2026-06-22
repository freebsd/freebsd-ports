--- uuid.c.orig	2008-03-07 10:49:59 UTC
+++ uuid.c
@@ -148,6 +148,7 @@ uuid_rc_t uuid_create(uuid_t **uuid)
 
     return UUID_RC_OK;
 }
+uuid_rc_t ossp_uuid_create(uuid_t **uuid) __attribute__((alias("uuid_create")));
 
 /* destroy UUID object */
 uuid_rc_t uuid_destroy(uuid_t *uuid)
@@ -166,6 +167,7 @@ uuid_rc_t uuid_destroy(uuid_t *uuid)
 
     return UUID_RC_OK;
 }
+uuid_rc_t ossp_uuid_destroy(uuid_t *uuid) __attribute__((alias("uuid_destroy")));
 
 /* clone UUID object */
 uuid_rc_t uuid_clone(const uuid_t *uuid, uuid_t **clone)
@@ -205,6 +207,7 @@ uuid_rc_t uuid_clone(const uuid_t *uuid, uuid_t **clon
 
     return UUID_RC_OK;
 }
+uuid_rc_t ossp_uuid_clone(const uuid_t *uuid, uuid_t **clone) __attribute__((alias("uuid_clone")));
 
 /* check whether UUID object represents "Nil UUID" */
 uuid_rc_t uuid_isnil(const uuid_t *uuid, int *result)
@@ -227,6 +230,7 @@ uuid_rc_t uuid_isnil(const uuid_t *uuid, int *result)
 
     return UUID_RC_OK;
 }
+uuid_rc_t ossp_uuid_isnil(const uuid_t *uuid, int *result) __attribute__((alias("uuid_isnil")));
 
 /* compare UUID objects */
 uuid_rc_t uuid_compare(const uuid_t *uuid1, const uuid_t *uuid2, int *result)
@@ -280,6 +284,7 @@ uuid_rc_t uuid_compare(const uuid_t *uuid1, const uuid
     result_exit:
     return UUID_RC_OK;
 }
+uuid_rc_t ossp_uuid_compare(const uuid_t *uuid1, const uuid_t *uuid2, int *result) __attribute__((alias("uuid_compare")));
 
 /* INTERNAL: unpack UUID binary presentation into UUID object
    (allows in-place operation for internal efficiency!) */
@@ -835,6 +840,7 @@ uuid_rc_t uuid_import(uuid_t *uuid, uuid_fmt_t fmt, co
 
     return rc;
 }
+uuid_rc_t ossp_uuid_import(uuid_t *uuid, uuid_fmt_t fmt, const void *data_ptr, size_t data_len) __attribute__((alias("uuid_import")));
 
 /* UUID exporting */
 uuid_rc_t uuid_export(const uuid_t *uuid, uuid_fmt_t fmt, void *data_ptr, size_t *data_len)
@@ -856,6 +862,7 @@ uuid_rc_t uuid_export(const uuid_t *uuid, uuid_fmt_t f
 
     return rc;
 }
+uuid_rc_t ossp_uuid_export(const uuid_t *uuid, uuid_fmt_t fmt, void *data_ptr, size_t *data_len) __attribute__((alias("uuid_export")));
 
 /* INTERNAL: brand UUID with version and variant */
 static void uuid_brand(uuid_t *uuid, unsigned int version)
@@ -1044,6 +1051,7 @@ uuid_rc_t uuid_load(uuid_t *uuid, const char *name)
 
     return UUID_RC_OK;
 }
+uuid_rc_t ossp_uuid_load(uuid_t *uuid, const char *name) __attribute__((alias("uuid_load")));
 
 /* INTERNAL: generate UUID version 3: name based with MD5 */
 static uuid_rc_t uuid_make_v3(uuid_t *uuid, unsigned int mode, va_list ap)
@@ -1191,6 +1199,7 @@ uuid_rc_t uuid_make(uuid_t *uuid, unsigned int mode, .
 
     return rc;
 }
+uuid_rc_t ossp_uuid_make(uuid_t *uuid, unsigned int mode, ...) __attribute__((alias("uuid_make")));
 
 /* translate UUID API error code into corresponding error string */
 char *uuid_error(uuid_rc_t rc)
@@ -1208,10 +1217,12 @@ char *uuid_error(uuid_rc_t rc)
     }
     return str;
 }
+char *ossp_uuid_error(uuid_rc_t rc) __attribute__((alias("uuid_error")));
 
 /* OSSP uuid version (link-time information) */
 unsigned long uuid_version(void)
 {
     return (unsigned long)(_UUID_VERSION);
 }
+unsigned long ossp_uuid_version(void) __attribute__((alias("uuid_version")));
 
