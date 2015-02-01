/* $FreeBSD$ */
#if 0
#define HAVE_HEIMDAL 1
#endif

#ifdef HAVE_HEIMDAL
#ifndef _KRB5_HEIMDAL_COMPAT_H
#define _KRB5_HEIMDAL_COMPAT_H

#include <com_err.h>

#if !defined(krb5_enc_tkt_part)
typedef	struct EncTicketPart krb5_enc_tkt_part;
#endif

/* Use real function.  MIT's krb5.h defines this as a macro. */
#undef krb5_princ_realm

typedef krb5int32		krb5_int32;
typedef heim_octet_string	krb5_octet;

#ifndef MAX_KEYTAB_NAME_LEN
#define	MAX_KEYTAB_NAME_LEN	255
#endif

#endif /* !_KRB5_HEIMDAL_COMPAT_H */
#endif /* HAVE_HEIMDAL */
