# New ports collection makefile for: DellMon
# Date created:    13 May 2011
# Whom:      Zenoss <zenoss@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	DellMon
PORTVERSION=	2.4

CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/epuzanov/${ZPACKPREFIX}${PORTNAME}/tarball/dellmon-2.4/
DISTNAME=	epuzanov-${ZPACKPREFIX}${PORTNAME}-dellmon-2.4-0-g9697659

MAINTAINER=	zenoss@experts-exchange.com
COMMENT=	Provides additional monitoring options for Dell machines

ZPACKGROUP=	community
WRKSRC=		${WRKDIR}/epuzanov-${ZPACKPREFIX}${PORTNAME}-a4ae347
ZPACKPREFIX=    ZenPacks.community.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.zenoss.mk"
.include <bsd.port.post.mk>
