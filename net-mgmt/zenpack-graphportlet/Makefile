# New ports collection makefile for: ShowGraphPortlet
# Date created:    12 May 2011
# Whom:      Zenoss <zenoss@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	ShowGraphPortlet
PORTVERSION=	1.03
CATEGORIES=	net-mgmt www
MASTER_SITES=   https://github.com/zenoss/${ZPACKPREFIX}${PORTNAME}/tarball/master/	
DISTNAME=       zenoss-${ZPACKPREFIX}${PORTNAME}-${TAG}

MAINTAINER=	zenoss@experts-exchange.com
COMMENT=	Enables users to show any graph/multi graph reports on their dashboard

ZPACKGROUP=	community
ZPACKPREFIX=	ZenPacks.SCC.
WRKSRC=         ${WRKDIR}/zenoss-${ZPACKPREFIX}${PORTNAME}-${TAG}
TAG=            0cf7678

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.zenoss.mk"
.include <bsd.port.post.mk>
