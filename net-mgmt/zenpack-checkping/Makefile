# Created by: Zenoss <zenoss@experts-exchange.com>
# $FreeBSD$

PORTNAME=	CheckPing
PORTVERSION=	1.0
CATEGORIES=	net-mgmt www
MASTER_SITES=	https://github.com/zenoss/${ZPACKPREFIX}${PORTNAME}/tarball/master/
DISTFILES=	zenoss-${ZPACKPREFIX}${PORTNAME}-${TAG}

MAINTAINER=	zenoss@experts-exchange.com
COMMENT=	Provides nagios ping check for Zenoss monitoring

PLIST_FILES=	zenoss/ZenPack/${ZPACK}
PLIST_DIRS=	zenoss/ZenPack
USES=		zenoss

ZPACKPREFIX=	ZenPacks.Nagios.
ZPACKGROUP=	community
WRKSRC=	${WRKDIR}/zenoss-${ZPACKPREFIX}${PORTNAME}-${TAG}
TAG=            0088e17

NO_STAGE=	yes
.include <bsd.port.mk>
