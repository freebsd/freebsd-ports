
$FreeBSD$

--- src/srs.c.orig
+++ src/srs.c
@@ -1,231 +1,126 @@
-/* $Cambridge: exim/exim-src/src/srs.c,v 1.8 2005/06/27 18:10:30 tom Exp $ */
+/* $Cambridge: exim/exim-src/src/srs.c,v 1.4 2005/02/17 11:58:26 ph10 Exp $ */
 
 /*************************************************
 *     Exim - an Internet mail transport agent    *
 *************************************************/
 
 /* SRS - Sender rewriting scheme support
-  (C)2004 Miles Wilton <miles@mirtol.com>
-
-  SRS Support Version: 1.0a
-
+  ©2004 Miles Wilton <miles@mirtol.com>
   License: GPL */
 
 #include "exim.h"
 #ifdef EXPERIMENTAL_SRS
 
-#include <srs_alt.h>
+#include <srs2.h>
 #include "srs.h"
 
-srs_t    *srs                   = NULL;
-uschar   *srs_db_forward        = NULL;
-uschar   *srs_db_reverse        = NULL;
+#define SRS_WARN_UNLESS(x) do { \
+               int __ret = (x); \
+               if (__ret != SRS_SUCCESS) \
+                       DEBUG(D_any) \
+                               debug_printf("srs: %s\n", srs_strerror(__ret)); \
+               } while(0)
 
+srs_t  *srs = NULL;
 
 /* srs_init just initialises libsrs and creates (if necessary)
    an srs object to use for all srs calls in this instance */
 
-int eximsrs_init()
-{
-  uschar *list = srs_config;
-  uschar secret_buf[SRS_MAX_SECRET_LENGTH];
-  uschar *secret = NULL;
-  uschar sbuf[4];
-  uschar *sbufp;
-
-  /* Check if this instance of Exim has not initialized SRS */
-  if(srs == NULL)
-  {
-    int co = 0;
-    int hashlen, maxage;
-    BOOL usetimestamp, usehash;
-
-    /* Copy config vars */
-    hashlen = srs_hashlength;
-    maxage = srs_maxage;
-    usetimestamp = srs_usetimestamp;
-    usehash = srs_usehash;
-
-    /* Pass srs_config var (overrides new config vars) */
-    co = 0;
-    if(srs_config != NULL)
-    {
-      secret = string_nextinlist(&list, &co, secret_buf, SRS_MAX_SECRET_LENGTH);
-
-      if((sbufp = string_nextinlist(&list, &co, sbuf, sizeof(sbuf))) != NULL)
-        maxage = atoi(sbuf);
-
-      if((sbufp = string_nextinlist(&list, &co, sbuf, sizeof(sbuf))) != NULL)
-        hashlen = atoi(sbuf);
-
-      if((sbufp = string_nextinlist(&list, &co, sbuf, sizeof(sbuf))) != NULL)
-        usetimestamp = atoi(sbuf);
-
-      if((sbufp = string_nextinlist(&list, &co, sbuf, sizeof(sbuf))) != NULL)
-        usehash = atoi(sbuf);
-    }
-
-    if(srs_hashmin == -1)
-      srs_hashmin = hashlen;
-
-    /* First secret specified in secrets? */
-    co = 0;
-    list = srs_secrets;
-    if(secret == NULL || *secret == '\0')
-    {
-      if((secret = string_nextinlist(&list, &co, secret_buf, SRS_MAX_SECRET_LENGTH)) == NULL)
-      {
-        log_write(0, LOG_MAIN | LOG_PANIC,
-            "SRS Configuration Error: No secret specified");
-        return DEFER;
-      }
-    }
-
-    /* Check config */
-    if(maxage < 0 || maxage > 365)
-    {
-      log_write(0, LOG_MAIN | LOG_PANIC,
-          "SRS Configuration Error: Invalid maximum timestamp age");
-      return DEFER;
-    }
-    if(hashlen < 1 || hashlen > 20 || srs_hashmin < 1 || srs_hashmin > 20)
-    {
-      log_write(0, LOG_MAIN | LOG_PANIC,
-          "SRS Configuration Error: Invalid hash length");
-      return DEFER;
-    }
-
-    if((srs = srs_open(secret, Ustrlen(secret), maxage, hashlen, srs_hashmin)) == NULL)
-    {
-      log_write(0, LOG_MAIN | LOG_PANIC,
-          "Failed to allocate SRS memory");
-      return DEFER;
-    }
-
-    srs_set_option(srs, SRS_OPTION_USETIMESTAMP, usetimestamp);
-    srs_set_option(srs, SRS_OPTION_USEHASH, usehash);
-
-    /* Extra secrets? */
-    while((secret = string_nextinlist(&list, &co, secret_buf, SRS_MAX_SECRET_LENGTH)) != NULL)
-        srs_add_secret(srs, secret, (Ustrlen(secret) > SRS_MAX_SECRET_LENGTH) ? SRS_MAX_SECRET_LENGTH :  Ustrlen(secret));
-
-    DEBUG(D_any)
-      debug_printf("SRS initialized\n");
-  }
-
-  return OK;
-}
-
-
-int eximsrs_done()
+int
+eximsrs_init()
 {
-  if(srs != NULL)
-    srs_close(srs);
-
-  srs = NULL;
-
-  return OK;
-}
+       char     sbuf[1024];
+       uschar  *list;
+       int              co;
 
+       char    *secret;
 
-int eximsrs_forward(uschar **result, uschar *orig_sender, uschar *domain)
-{
-  char res[512];
-  int n;
+       if (srs == NULL) {
+               srs = srs_new();
 
-  if((n = srs_forward(srs, orig_sender, domain, res, sizeof(res))) & SRS_RESULT_FAIL)
-  {
-    DEBUG(D_any)
-      debug_printf("srs_forward failed (%s, %s): %s\n", orig_sender, domain, srs_geterrormsg(n));
-    return DEFER;
-  }
+               if (srs_secrets == NULL) {
+                       log_write(0, LOG_MAIN | LOG_PANIC,
+                                                       "SRS: No secrets specified");
+                       return DEFER;
+               }
 
-  *result = string_copy(res);
-  return OK;
-}
+               /* Get config */
+               list = srs_secrets;
 
+               co = 0;
+               while ((secret = string_nextinlist(&list, &co,
+                                               sbuf, sizeof(sbuf))) != NULL) {
+                       SRS_WARN_UNLESS(srs_add_secret(srs, secret));
+               }
 
-int eximsrs_reverse(uschar **result, uschar *address)
-{
-  char res[512];
-  int n;
+               SRS_WARN_UNLESS(srs_set_alwaysrewrite(srs, srs_alwaysrewrite));
+               if (srs_hashlength != -1)
+                       SRS_WARN_UNLESS(srs_set_hashlength(srs, srs_hashlength));
+               if (srs_hashmin != -1)
+                       SRS_WARN_UNLESS(srs_set_hashmin(srs, srs_hashmin));
+               if (srs_maxage != -1)
+                       SRS_WARN_UNLESS(srs_set_maxage(srs, srs_maxage));
+               if (srs_separator != NULL)
+                       SRS_WARN_UNLESS(srs_set_separator(srs, srs_separator[0]));
 
-  if((n = srs_reverse(srs, address, res, sizeof(res))) & SRS_RESULT_FAIL)
-  {
-    DEBUG(D_any)
-      debug_printf("srs_reverse failed (%s): %s\n", address, srs_geterrormsg(n));
-    if(n == SRS_RESULT_NOTSRS || n == SRS_RESULT_BADSRS)
-      return DECLINE;
-    if(n == SRS_RESULT_BADHASH || n == SRS_RESULT_BADTIMESTAMP || n == SRS_RESULT_TIMESTAMPEXPIRED)
-      return FAIL;
-    return DEFER;
-  }
+               DEBUG(D_any)
+                       debug_printf("SRS initialised\n");
+       }
 
-  *result = string_copy(res);
-  return OK;
+       return OK;
 }
 
-
-int eximsrs_db_set(BOOL reverse, uschar *srs_db)
+int
+eximsrs_done()
 {
-  if(reverse)
-    srs_db_reverse = (srs_db == NULL ? NULL : string_copy(srs_db));
-  else
-    srs_db_forward = (srs_db == NULL ? NULL : string_copy(srs_db));
-
-  if(srs_set_db_functions(srs, (srs_db_forward ? eximsrs_db_insert : NULL),
-                               (srs_db_reverse ? eximsrs_db_lookup : NULL)) & SRS_RESULT_FAIL)
-    return DEFER;
-
-  return OK;
+       if (srs != NULL)
+               srs_free(srs);
+       srs = NULL;
+       return OK;
 }
 
-
-srs_result eximsrs_db_insert(srs_t *srs, char *data, uint data_len, char *result, uint result_len)
+int
+eximsrs_forward(uschar **result, uschar *sender, uschar *domain)
 {
-  uschar *res;
-  uschar buf[64];
-
-  if(srs_db_forward == NULL)
-    return SRS_RESULT_DBERROR;
-
-  srs_db_address = string_copyn(data, data_len);
-  if(srs_generate_unique_id(srs, srs_db_address, buf, 64) & SRS_RESULT_FAIL)
-    return SRS_RESULT_DBERROR;
-
-  srs_db_key = string_copyn(buf, 16);
-
-  if((res = expand_string(srs_db_forward)) == NULL)
-    return SRS_RESULT_DBERROR;
-
-  if(result_len < 17)
-    return SRS_RESULT_DBERROR;
+       char     res[1024];
+       int              ret;
 
-  Ustrncpy(result, srs_db_key, result_len);
+       ret = srs_forward(srs, res, sizeof(res), sender, domain);
+       if (ret != SRS_SUCCESS) {
+               DEBUG(D_any)
+                       debug_printf("srs_forward failed (%s, %s): s\n",
+				sender, domain, srs_strerror(ret));
+               return DEFER;
+       }
 
-  return SRS_RESULT_OK;
+       *result = string_copy(res);
+       return OK;
 }
 
-
-srs_result eximsrs_db_lookup(srs_t *srs, char *data, uint data_len, char *result, uint result_len)
+int
+eximsrs_reverse(uschar **result, uschar *sender)
 {
-  uschar *res;
-
-  if(srs_db_reverse == NULL)
-    return SRS_RESULT_DBERROR;
-
-  srs_db_key = string_copyn(data, data_len);
-  if((res = expand_string(srs_db_reverse)) == NULL)
-    return SRS_RESULT_DBERROR;
+	char	res[1024];
+	int		ret;
 
-  if(Ustrlen(res) >= result_len)
-    return SRS_RESULT_ADDRESSTOOLONG;
+       ret = srs_reverse(srs, res, sizeof(res), sender);
+       if (ret != SRS_SUCCESS) {
+               switch (SRS_ERROR_TYPE(ret)) {
+                       case SRS_ERRTYPE_CONFIG:
+                               /* This should never happen */
+                               return DEFER;
+                       case SRS_ERRTYPE_INPUT:
+                               /* This should never happen */
+                               return DEFER;
+                       case SRS_ERRTYPE_SYNTAX:
+                               return DECLINE;
+                       case SRS_ERRTYPE_SRS:
+                               return FAIL;
+		}
+	}
 
-  strncpy(result, res, result_len);
+	*result = string_copy(res);
 
-  return SRS_RESULT_OK;
+	return OK;
 }
-
-
 #endif
-
