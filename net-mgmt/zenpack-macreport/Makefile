# New ports collection makefile for: MACReport
# Date created:    13 May 2011
# Whom:      Zenoss <zenoss@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	MACReport
PORTVERSION=	1.0.1
CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/zenoss/${ZPACKPREFIX}${PORTNAME}/zipball/master/
DISTNAME=	zenoss-${ZPACKPREFIX}${PORTNAME}-${TAG}

MAINTAINER=	zenoss@experts-exchange.com
COMMENT=	Lists MAC address and the Device and Interface associated info

USE_ZIP=	yes
ZPACKGROUP=	community
WRKSRC=	${WRKDIR}/zenoss-${ZPACKPREFIX}${PORTNAME}-${TAG}
TAG=	b345f53

ZPACKPREFIX=	ZenPacks.sodonnell.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.zenoss.mk"
.include <bsd.port.post.mk>
