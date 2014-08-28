# Created by: Zenoss <zenoss@experts-exchange.com>
# $FreeBSD$

PORTNAME=	libvirt
PORTVERSION=	1.96
PORTREVISION=	5
CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/zenoss/${ZPACKPREFIX}${PORTNAME}/tarball/master/
DISTNAME=	zenoss-${ZPACKPREFIX}${PORTNAME}-${TAG}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides monitoring of virtualization servers through Zenoss

LICENSE=	GPLv2

RUN_DEPENDS=	libvirt>=0.9.1:${PORTSDIR}/devel/libvirt

PLIST_FILES=	zenoss/ZenPack/${ZPACK}
PLIST_DIRS=	zenoss/ZenPack
USES=		zenoss

ZPACKPREFIX=	ZenPacks.community.
ZPACKGROUP=	community
WRKSRC=		${WRKDIR}/zenoss-${ZPACKPREFIX}${PORTNAME}-${TAG}
TAG=		4113cfe

NO_STAGE=	yes
.include <bsd.port.mk>
