# New ports collection makefile for: libvirt
# Date created:    20 May 2011
# Whom:      Zenoss <zenoss@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	libvirt
PORTVERSION=    1.96
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=   https://github.com/zenoss/${ZPACKPREFIX}${PORTNAME}/tarball/master/
DISTNAME=       zenoss-${ZPACKPREFIX}${PORTNAME}-${TAG}

MAINTAINER=	zenoss@experts-exchange.com
COMMENT=	Provides monitoring of virtualization servers through Zenoss

LICENSE=	GPLv2

RUN_DEPENDS=	libvirt>=0.9.1:${PORTSDIR}/devel/libvirt

PLIST_FILES=	zenoss/ZenPack/${ZPACK}
PLIST_DIRS=	zenoss/ZenPack

ZPACKPREFIX=	ZenPacks.community.
ZPACKGROUP=	community
WRKSRC=  ${WRKDIR}/zenoss-${ZPACKPREFIX}${PORTNAME}-${TAG}
TAG=  4113cfe

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.zenoss.mk"
.include <bsd.port.post.mk>
