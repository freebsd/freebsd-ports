# New ports collection makefile for:	sslwrap
# Version required:	2.0.5
# Date created:		1999 november 7.
# Whom:			Zahemszky, Gabor <ZGabor at CoDe dot HU>
#
# $FreeBSD$
#

DISTNAME=	sslwrap
PKGNAME=	sslwrap-2.0.5
CATEGORIES=	security
MASTER_SITES=	http://www.rickk.com/sslwrap/

MAINTAINER=	ZGabor@CoDe.HU

RUN_DEPENDS=	${PREFIX}/lib/libssl.a:${PORTSDIR}/security/openssl
BUILD_DEPENDS=	${PREFIX}/include/openssl/ssl.h:${PORTSDIR}/security/openssl

.if defined(USA_RESIDENT) && ${USA_RESIDENT} == YES
LIB_DEPENDS=	rsaref.2:${PORTSDIR}/security/rsaref
MAKE_ENV+=	EXTRA_SSL_LIBS="-lRSAglue -lrsaref"
.endif

WRKSRC=		${WRKDIR}/sslwrap205

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sslwrap ${PREFIX}/bin/sslwrap
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/sslwrap
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/docs.html \
			${PREFIX}/share/doc/sslwrap
.endif

.include <bsd.port.mk>
