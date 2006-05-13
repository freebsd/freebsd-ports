# New ports collection makefile for:	sslwrap
# Date created:		1999 november 7.
# Whom:			Zahemszky, Gabor <ZGabor at CoDe dot HU>
#
# $FreeBSD$
#

PORTNAME=	sslwrap
PORTVERSION=	2.0.6
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.rickk.com/sslwrap/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another SSL Wrapper application, which uses SSLEay/OpenSSL

USE_OPENSSL=	YES

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:S/.//g}

post-patch:
	${REINPLACE_CMD} -e \
		's/SSL_OP_NON_EXPORT_FIRST/SSL_OP_CIPHER_SERVER_PREFERENCE/g' \
		${WRKSRC}/s_server.c
	${REINPLACE_CMD} -e \
		's,%%OPENSSL%%,openssl/,g' \
		${WRKSRC}/s_server.c ${WRKSRC}/s_cb.c ${WRKSRC}/apps.h ${WRKSRC}/s_socket.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sslwrap ${PREFIX}/bin/sslwrap
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/sslwrap
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/docs.html \
			${PREFIX}/share/doc/sslwrap
.endif

.include <bsd.port.mk>
