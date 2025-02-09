--- src/libipsec/libpfkey.h.orig	2012-08-23 18:10:45.000000000 +0700
+++ src/libipsec/libpfkey.h	2025-02-09 14:39:31.913248000 +0700
@@ -34,6 +34,8 @@
 #ifndef _LIBPFKEY_H
 #define _LIBPFKEY_H
 
+#include <sys/param.h>
+
 #ifndef KAME_LIBPFKEY_H
 #define KAME_LIBPFKEY_H
 
@@ -64,6 +66,14 @@
 #define __ipsec_const const
 #endif
 
+#if __FreeBSD_version >= 1500019
+typedef c_caddr_t c_ipsec_policy_t;
+#define __ipsec_nconst const
+#else
+typedef caddr_t c_ipsec_policy_t;
+#define __ipsec_nconst
+#endif
+
 struct pfkey_send_sa_args {
 	int 		so;			/* socket */
 	u_int		type;			
@@ -107,9 +117,9 @@
 void ipsec_hexdump __P((const void *, int));
 const char *ipsec_strerror __P((void));
 void kdebug_sadb __P((struct sadb_msg *));
-ipsec_policy_t ipsec_set_policy __P((__ipsec_const char *, int));
-int  ipsec_get_policylen __P((ipsec_policy_t));
-char *ipsec_dump_policy __P((ipsec_policy_t, __ipsec_const char *));
+ipsec_policy_t ipsec_set_policy __P((__ipsec_nconst char *, int));
+int  ipsec_get_policylen __P((c_ipsec_policy_t));
+char *ipsec_dump_policy __P((c_ipsec_policy_t, __ipsec_nconst char *));
 
 /* PFKey Routines */
 
