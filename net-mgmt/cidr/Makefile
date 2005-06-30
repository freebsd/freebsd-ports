# New ports collection makefile for:   sqsh
# Date created:		18 Jun 2000
# Whom:			Domas Mituzas <midom@dammit.lt>
#
# $FreeBSD$

PORTNAME=	cidr
PORTVERSION=	2.3.2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://critical.ch/distfiles/
MASTER_SITE_SUBDIR=	nork
DISTNAME=	cidr-current

MAINTAINER=	midom@dammit.lt
COMMENT=	RFC 1878 subnet calculator / helper

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ALL_TARGET=	cidr

MAN1=		cidr.1
PLIST_FILES=	bin/cidr

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cidr ${PREFIX}/bin/cidr
	${INSTALL_MAN} ${WRKSRC}/cidr.1 ${PREFIX}/man/man1/cidr.1

.include <bsd.port.mk>
