# New ports collection Makefile for: deviceAdvDetail
# Date created:    11 May 2011
# Whom:      Zenoss <zenoss@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	deviceAdvDetail
PORTVERSION=	2.7.3
CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/epuzanov/${ZPACKPREFIX}${PORTNAME}/tarball/deviceadvdetail-2.7/
DISTNAME=	epuzanov-${ZPACKPREFIX}${PORTNAME}-deviceadvdetail-2.7-0-g4cc7c48

MAINTAINER=	zenoss@experts-exchange.com
COMMENT=	Provides additional hardware details for Zenoss

ZPACKGROUP=	community
WRKSRC=	${WRKDIR}/epuzanov-${ZPACKPREFIX}${PORTNAME}-cfbd596

ZPACK=	${ZPACKPREFIX}${PORTNAME}-2.7-${PYTHON_VERSION:S/thon//}.egg
ZPACKPREFIX=	ZenPacks.community.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.zenoss.mk"
.include <bsd.port.post.mk>
