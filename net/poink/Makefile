# New ports collection makefile for:    poink
# Date created:         12.04.2002
# Whom:                 janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	poink
PORTVERSION=	1.6
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.freenet.de/pub/.disk0/ftp.openbsd.org/pub/OpenBSD/distfiles/ \
		http://voodoo.bawue.com/download/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nosuid, secure ping like utility

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_ZIP=	yes

MAN1=		poink.1
PLIST_FILES=	bin/poink

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/poink ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ping.1 ${PREFIX}/man/man1/poink.1

.include <bsd.port.mk>
