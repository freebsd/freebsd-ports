# New ports collection makefile for:	sslwrap
# Date created:		1999 november 7.
# Whom:			Zahemszky, Gabor <ZGabor at CoDe dot HU>
#
# $FreeBSD$
#

PORTNAME=	sslwrap
PORTVERSION=	2.0.6
CATEGORIES=	security
MASTER_SITES=	http://www.quiltaholic.com/rickk/sslwrap/
DISTNAME=	${PORTNAME}

MAINTAINER=	ZGabor@CoDe.HU
COMMENT=	Another SSL Wrapper application, which uses SSLEay/OpenSSL

USE_OPENSSL=	YES
USE_REINPLACE=	YES

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:S/.//g}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

post-patch:
	${REINPLACE_CMD} -e 's/SSL_OP_NON_EXPORT_FIRST/SSL_OP_CIPHER_SERVER_PREFERENCE/g' ${WRKSRC}/s_server.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sslwrap ${PREFIX}/bin/sslwrap
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/sslwrap
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/docs.html \
			${PREFIX}/share/doc/sslwrap
.endif

.include <bsd.port.post.mk>
