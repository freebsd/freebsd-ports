--- src/filed/acl.c.orig	2015-08-13 13:52:24 UTC
+++ src/filed/acl.c
@@ -927,7 +927,7 @@ static bacl_rtn_code generic_set_acl_on_
  * Define the supported ACL streams for this OS
  */
 static int os_access_acl_streams[1] = {
-   STREAM_ACL_DARWIN_ACCESS_ACL
+   STREAM_ACL_DARWIN_ACCESS
 };
 static int os_default_acl_streams[1] = {
    -1
@@ -988,11 +988,11 @@ static bacl_rtn_code (*os_restore_acl_st
  * Define the supported ACL streams for these OSes
  */
 static int os_access_acl_streams[2] = {
-   STREAM_ACL_FREEBSD_ACCESS_ACL,
-   STREAM_ACL_FREEBSD_NFS4_ACL
+   STREAM_ACL_FREEBSD_ACCESS,
+   STREAM_ACL_FREEBSD_NFS4
 };
 static int os_default_acl_streams[1] = {
-   STREAM_ACL_FREEBSD_DEFAULT_ACL
+   STREAM_ACL_FREEBSD_DEFAULT
 };
 
 static bacl_rtn_code freebsd_backup_acl_streams(JCR *jcr, FF_PKT *ff_pkt)
@@ -1065,7 +1065,7 @@ static bacl_rtn_code freebsd_backup_acl_
          return bacl_rtn_fatal;
 
       if (jcr->acl_ctx->content_length > 0) {
-         if (send_acl_stream(jcr, STREAM_ACL_FREEBSD_NFS4_ACL) == bacl_rtn_fatal)
+         if (send_acl_stream(jcr, STREAM_ACL_FREEBSD_NFS4) == bacl_rtn_fatal)
             return bacl_rtn_fatal;
       }
       break;
@@ -1077,7 +1077,7 @@ static bacl_rtn_code freebsd_backup_acl_
          return bacl_rtn_fatal;
 
       if (jcr->acl_ctx->content_length > 0) {
-         if (send_acl_stream(jcr, STREAM_ACL_FREEBSD_ACCESS_ACL) == bacl_rtn_fatal)
+         if (send_acl_stream(jcr, STREAM_ACL_FREEBSD_ACCESS) == bacl_rtn_fatal)
             return bacl_rtn_fatal;
       }
 
@@ -1088,7 +1088,7 @@ static bacl_rtn_code freebsd_backup_acl_
          if (generic_get_acl_from_os(jcr, BACL_TYPE_DEFAULT) == bacl_rtn_fatal)
             return bacl_rtn_fatal;
          if (jcr->acl_ctx->content_length > 0) {
-            if (send_acl_stream(jcr, STREAM_ACL_FREEBSD_DEFAULT_ACL) == bacl_rtn_fatal)
+            if (send_acl_stream(jcr, STREAM_ACL_FREEBSD_DEFAULT) == bacl_rtn_fatal)
                return bacl_rtn_fatal;
          }
       }
@@ -1113,13 +1113,13 @@ static bacl_rtn_code freebsd_restore_acl
     */
    switch (stream) {
    case STREAM_UNIX_ACCESS_ACL:
-   case STREAM_ACL_FREEBSD_ACCESS_ACL:
+   case STREAM_ACL_FREEBSD_ACCESS:
    case STREAM_UNIX_DEFAULT_ACL:
-   case STREAM_ACL_FREEBSD_DEFAULT_ACL:
+   case STREAM_ACL_FREEBSD_DEFAULT:
       acl_enabled = pathconf(jcr->last_fname, _PC_ACL_EXTENDED);
       acl_type_name = "POSIX";
       break;
-   case STREAM_ACL_FREEBSD_NFS4_ACL:
+   case STREAM_ACL_FREEBSD_NFS4:
 #if defined(_PC_ACL_NFS4)
       acl_enabled = pathconf(jcr->last_fname, _PC_ACL_NFS4);
 #endif
@@ -1159,12 +1159,12 @@ static bacl_rtn_code freebsd_restore_acl
     */
    switch (stream) {
    case STREAM_UNIX_ACCESS_ACL:
-   case STREAM_ACL_FREEBSD_ACCESS_ACL:
+   case STREAM_ACL_FREEBSD_ACCESS:
       return generic_set_acl_on_os(jcr, BACL_TYPE_ACCESS, content, content_length);
    case STREAM_UNIX_DEFAULT_ACL:
-   case STREAM_ACL_FREEBSD_DEFAULT_ACL:
+   case STREAM_ACL_FREEBSD_DEFAULT:
       return generic_set_acl_on_os(jcr, BACL_TYPE_DEFAULT, content, content_length);
-   case STREAM_ACL_FREEBSD_NFS4_ACL:
+   case STREAM_ACL_FREEBSD_NFS4:
       return generic_set_acl_on_os(jcr, BACL_TYPE_NFS4, content, content_length);
    default:
       break;
@@ -1273,11 +1273,11 @@ static bacl_rtn_code (*os_restore_acl_st
  * Define the supported ACL streams for this OS
  */
 static int os_access_acl_streams[1] = {
-   STREAM_ACL_TRU64_ACCESS_ACL
+   STREAM_ACL_TRU64_ACCESS
 };
 static int os_default_acl_streams[2] = {
-   STREAM_ACL_TRU64_DEFAULT_ACL,
-   STREAM_ACL_TRU64_DEFAULT_DIR_ACL
+   STREAM_ACL_TRU64_DEFAULT,
+   STREAM_ACL_TRU64_DEFAULT_DIR
 };
 
 static bacl_rtn_code tru64_backup_acl_streams(JCR *jcr, FF_PKT *ff_pkt)
@@ -1564,8 +1564,8 @@ char *acl_strerror(int);
  * Define the supported ACL streams for this OS
  */
 static int os_access_acl_streams[2] = {
-   STREAM_ACL_SOLARIS_ACLENT,
-   STREAM_ACL_SOLARIS_ACE
+   STREAM_ACL_SOLARIS_POSIX,
+   STREAM_ACL_SOLARIS_NFS4
 };
 static int os_default_acl_streams[1] = {
    -1
@@ -1653,10 +1653,10 @@ static bacl_rtn_code solaris_backup_acl_
 
       switch (acl_type(aclp)) {
       case ACLENT_T:
-         stream_status = send_acl_stream(jcr, STREAM_ACL_SOLARIS_ACLENT);
+         stream_status = send_acl_stream(jcr, STREAM_ACL_SOLARIS_POSIX);
          break;
       case ACE_T:
-         stream_status = send_acl_stream(jcr, STREAM_ACL_SOLARIS_ACE);
+         stream_status = send_acl_stream(jcr, STREAM_ACL_SOLARIS_NFS4);
          break;
       default:
          break;
@@ -1673,8 +1673,8 @@ static bacl_rtn_code solaris_restore_acl
    acl_t *aclp;
    int acl_enabled, error;
 
-   if (stream != STREAM_UNIX_ACCESS_ACL || stream != STREAM_ACL_SOLARIS_ACLENT ||
-       stream != STREAM_ACL_SOLARIS_ACE) {
+   if (stream != STREAM_UNIX_ACCESS_ACL || stream != STREAM_ACL_SOLARIS_POSIX ||
+       stream != STREAM_ACL_SOLARIS_NFS4) {
       return bacl_rtn_error;
    }
 
@@ -1709,7 +1709,7 @@ static bacl_rtn_code solaris_restore_acl
     * On a filesystem with ACL support make sure this particular ACL type can be restored.
     */
    switch (stream) {
-   case STREAM_ACL_SOLARIS_ACLENT:
+   case STREAM_ACL_SOLARIS_POSIX:
       /*
        * An aclent can be restored on filesystems with _ACL_ACLENT_ENABLED or _ACL_ACE_ENABLED support.
        */
@@ -1720,7 +1720,7 @@ static bacl_rtn_code solaris_restore_acl
          return bacl_rtn_error;
       }
       break;
-   case STREAM_ACL_SOLARIS_ACE:
+   case STREAM_ACL_SOLARIS_NFS4:
       /*
        * An ace can only be restored on a filesystem with _ACL_ACE_ENABLED support.
        */
@@ -1750,7 +1750,7 @@ static bacl_rtn_code solaris_restore_acl
     * Validate that the conversion gave us the correct acl type.
     */
    switch (stream) {
-   case STREAM_ACL_SOLARIS_ACLENT:
+   case STREAM_ACL_SOLARIS_POSIX:
       if (acl_type(aclp) != ACLENT_T) {
          Mmsg1(jcr->errmsg,
                _("wrong encoding of acl type in acl stream on file \"%s\"\n"),
@@ -1758,7 +1758,7 @@ static bacl_rtn_code solaris_restore_acl
          return bacl_rtn_error;
       }
       break;
-   case STREAM_ACL_SOLARIS_ACE:
+   case STREAM_ACL_SOLARIS_NFS4:
       if (acl_type(aclp) != ACE_T) {
          Mmsg1(jcr->errmsg,
                _("wrong encoding of acl type in acl stream on file \"%s\"\n"),
@@ -1802,7 +1802,7 @@ static bacl_rtn_code solaris_restore_acl
  * Define the supported ACL streams for this OS
  */
 static int os_access_acl_streams[1] = {
-   STREAM_ACL_SOLARIS_ACLENT
+   STREAM_ACL_SOLARIS_POSIX
 };
 static int os_default_acl_streams[1] = {
    -1
@@ -1861,7 +1861,7 @@ static bacl_rtn_code solaris_backup_acl_
             pm_strcpy(jcr->acl_ctx->content, acl_text);
          actuallyfree(acl_text);
          free(acls);
-         return send_acl_stream(jcr, STREAM_ACL_SOLARIS_ACLENT);
+         return send_acl_stream(jcr, STREAM_ACL_SOLARIS_POSIX);
       }
 
       berrno be;
