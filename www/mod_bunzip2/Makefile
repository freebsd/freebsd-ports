# New ports collection makefile for:	mod_bunzip2
# Date created:		26 January 2002
# Whom:			Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=		mod_bunzip2
PORTVERSION=		1
CATEGORIES=		www
MASTER_SITES=		http://www.oldach.net/
DISTNAME=		${PORTNAME}

MAINTAINER=		mod_bunzip2@oldach.net
COMMENT=	Apache module for server-side decompression of bzip2 files

BUILD_DEPENDS=	${APXS}:${APACHE_PORT}
RUN_DEPENDS=	${APXS}:${APACHE_PORT}

USE_BZIP2=		yes
WRKSRC=			${WRKDIR}/${PORTNAME}-2
APXS?=			${LOCALBASE}/sbin/apxs
APACHE_PORT?=		${PORTSDIR}/www/apache13

do-build:
	cd ${WRKSRC}; ${APXS} -c -lbz2 mod_bunzip2.c

do-install:
	${INSTALL_DATA} ${WRKSRC}/mod_bunzip2.so ${PREFIX}/libexec/apache/
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
