# Created by: Zenoss <zenoss@experts-exchange.com>
# $FreeBSD$

PORTNAME=	ShowGraphPortlet
PORTVERSION=	1.03
CATEGORIES=	net-mgmt www
MASTER_SITES=   https://github.com/zenoss/${ZPACKPREFIX}${PORTNAME}/tarball/master/	
DISTNAME=       zenoss-${ZPACKPREFIX}${PORTNAME}-${TAG}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enables users to show any graph/multi graph reports on their dashboard

PLIST_FILES=	zenoss/ZenPack/${ZPACK}
PLIST_DIRS=	zenoss/ZenPack
USES=		zenoss

ZPACKGROUP=	community
ZPACKPREFIX=	ZenPacks.SCC.
WRKSRC=         ${WRKDIR}/zenoss-${ZPACKPREFIX}${PORTNAME}-${TAG}
TAG=            0cf7678

NO_STAGE=	yes
.include <bsd.port.mk>
