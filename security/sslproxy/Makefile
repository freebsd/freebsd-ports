# New ports collection makefile for:	sslproxy
# Date created:		11 February 1999
# Whom:			Alex Le Heux
#
# $FreeBSD$
#

PORTNAME=	sslproxy
PORTVERSION=	20000129
CATEGORIES=	security
MASTER_SITES=	http://mirror2.unixfreunde.de/	\
		http://freebsd.unixfreunde.de/sources/
DISTNAME=	sslproxy.2000_Jan_29

MAINTAINER=	alexlh@funk.org
COMMENT=	Proxies non-SSL request over an SSL connection

PORTDOCS=	README.txt dummyCert.pem

PLIST_FILES=	bin/sslproxy

USE_OPENSSL=	YES

DEPRECATED=	Abandoned upstream
EXPIRATION_DATE=	2013-02-28

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sslproxy ${PREFIX}/bin/sslproxy
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/sslproxy
	${INSTALL_DATA} ${WRKSRC}/README.txt ${WRKSRC}/dummyCert.pem \
			${PREFIX}/share/doc/sslproxy
.endif

.include <bsd.port.mk>
