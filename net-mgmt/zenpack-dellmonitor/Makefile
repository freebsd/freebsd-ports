# Created by: Zenoss <zenoss@experts-exchange.com>
# $FreeBSD$

PORTNAME=	DellMonitor
PORTVERSION=	2.1.0
CATEGORIES=	net-mgmt
MASTER_SITES=	http://dev.zenoss.org/trac/changeset/26194/tags/zenoss-3.1.0/zenpacks/
DISTFILES=	${ZPACKPREFIX}${PORTNAME}?old_path=%2F\&format=zip

MAINTAINER=	zenoss@experts-exchange.com
COMMENT=	Provides Zenoss monitoring options for Dell machines

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

PLIST_FILES=	zenoss/ZenPack/${ZPACK}
PLIST_DIRS=	zenoss/ZenPack
USES=		zenoss

BROKEN=		fails to fetch

USE_ZIP=	yes
ZPACKGROUP=	core
WRKSRC=	        ${WRKDIR}/tags/zenoss-3.1.0/zenpacks/${ZPACKPREFIX}${PORTNAME}/

NO_STAGE=	yes
.include <bsd.port.mk>
