# New ports collection makefile for:   sqsh
# Date created:		18 Jun 2000
# Whom:			Domas Mituzas <midom@dammit.lt>
#
# $FreeBSD$

PORTNAME=	cidr
PORTVERSION=	2.3
CATEGORIES=	net
MASTER_SITES=	http://home.netcom.com/~naym/cidr/
DISTNAME=	cidr-current

MAINTAINER=	midom@dammit.lt

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

ALL_TARGET=	cidr

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cidr ${PREFIX}/bin/cidr
	${INSTALL_MAN} ${WRKSRC}/cidr.1 ${PREFIX}/man/man1/cidr.1

MAN1=	cidr.1

.include <bsd.port.mk>
