# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mtrace
PORTVERSION=	5.2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multicast traceroute program for IPv4

PLIST_FILES=	sbin/mtrace man/man8/mtrace.8.gz

ALL_TARGET=	mtrace

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtrace ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/mtrace.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
