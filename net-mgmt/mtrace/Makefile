# New ports collection makefile for:	mtrace
# Date created:		28 September 2006
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mtrace
PORTVERSION=	5.2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multicast traceroute program for IPv4

MAN8=		mtrace.8

ALL_TARGET=	mtrace

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtrace ${PREFIX}/sbin/mtrace
	${INSTALL_MAN} ${WRKSRC}/mtrace.8 ${PREFIX}/man/man8

PLIST_FILES=	sbin/mtrace

.include <bsd.port.mk>
