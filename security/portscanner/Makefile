# New ports collection makefile for:   portscanner
# Date created:        11 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	portscanner
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.ameth.org/~veilleux/PortScan/
DISTNAME=	PortScanner-${PORTVERSION}

MAINTAINER=	billf@FreeBSD.org
COMMENT=	A simple and easy to use TCP port scanner

PLIST_FILES=	bin/portscanner

do-build:
	@ ${CC} -o ${WRKSRC}/portscanner ${CFLAGS} ${WRKSRC}/portscanner.c

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/portscanner ${PREFIX}/bin

.include <bsd.port.mk>
