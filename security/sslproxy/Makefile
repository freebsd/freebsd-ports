# New ports collection makefile for:	sslproxy
# Version required:	1998_Jun_14
# Date created:		11 February 1999
# Whom:			Alex Le Heux
#
# $FreeBSD$
#

DISTNAME=	sslproxy.1998_Jun_14
PKGNAME=	sslproxy-19980614
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.obdev.at/pub/Products/sslproxy/

MAINTAINER=	alexlh@funk.org

USE_OPENSSL=	RSA

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sslproxy ${PREFIX}/bin/sslproxy
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/sslproxy
	${INSTALL_DATA} ${WRKSRC}/README.txt ${WRKSRC}/dummyCert.pem \
			${PREFIX}/share/doc/sslproxy
.endif

.include <bsd.port.mk>
