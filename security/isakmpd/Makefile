# Created by: Martti Kuparinen <martti.kuparinen@iki.fi>

PORTNAME=	isakmpd
PORTVERSION=	20041207
PORTREVISION=	3
CATEGORIES=	security net
MASTER_SITES=	LOCAL/simon

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenBSD IKE daemon

# this is not compatible with cross build - there's no other way
.if !exists(/usr/include/netipsec/ipsec.h) && !exists(/usr/include/netinet6/ipsec.h)
BROKEN=		requires IPsec support
.endif

DEPRECATED=	15+ years old and broken on multiple versions
EXPIRATION_DATE=2022-03-31

# If keynote is in use, bring the dependency
.if defined(USE_KEYNOTE)
BUILD_DEPENDS+=	keynote:security/keynote
.endif

USES=		uidfix ssl
USE_RC_SUBR=	isakmpd
MAKE_ENV+=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man/man

MAKE_JOBS_UNSAFE=	yes
.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	variable has incomplete type 'X509_STORE_CTX' (aka 'struct x509_store_ctx_st')
BROKEN_FreeBSD_13=	variable has incomplete type 'X509_STORE_CTX' (aka 'struct x509_store_ctx_st')
BROKEN_FreeBSD_14=	variable has incomplete type 'X509_STORE_CTX' (aka 'struct x509_store_ctx_st')
.endif

OPENSSLINC?=	/usr/include
OPENSSLLIB?=	/usr/lib
MAKE_ENV+=	OPENSSLINC="${OPENSSLINC}" OPENSSLLIB="${OPENSSLLIB}"

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-patch:
.for f in conf.h ike_auth.c isakmpd.8 isakmpd.conf.5 isakmpd.policy.5 policy.h
	${REINPLACE_CMD} -e "s!/etc/!${PREFIX}/etc/!" ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -e "s!netinet6/ipsec.h!netipsec/ipsec.h!" \
		${WRKSRC}/sysdep/freebsd/sysdep-os.h

.include <bsd.port.post.mk>
