# New ports collection makefile for:    poink
# Date created:         12.04.2002
# Whom:                 janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	poink
PORTVERSION=	1.6
CATEGORIES=	net
MASTER_SITES=	http://coredump.cx/~lcamtuf/soft/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nosuid, secure ping like utility

USE_ZIP=	yes

.if ${MACHINE_ARCH} == "sparc64"
BROKEN=		"Hostname resolution broken on ${MACHINE_ARCH}"
.endif

MAN1=		poink.1
PLIST_FILES=	bin/poink

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/poink ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ping.1 ${PREFIX}/man/man1/poink.1

.include <bsd.port.mk>
