# New ports collection makefile for:	mod_bunzip2
# Date created:		26 January 2002
# Whom:			Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	mod_bunzip2
PORTVERSION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.oldach.net/
DISTNAME=	${PORTNAME}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for server-side decompression of bzip2 files

PLIST_FILES=	libexec/apache/mod_bunzip2.so
USE_APACHE=	yes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-2

do-build:
	cd ${WRKSRC}; ${APXS} -c -lbz2 mod_bunzip2.c

do-install:
	${INSTALL_DATA} ${WRKSRC}/mod_bunzip2.so ${PREFIX}/libexec/apache/
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
