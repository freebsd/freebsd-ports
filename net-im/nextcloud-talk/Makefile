PORTNAME=	talk
PORTVERSION=	22.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net-im www
DISTNAME=	spreed-${DISTVERSIONPREFIX}${DISTVERSION}
DIST_SUBDIR=	nextcloud

MASTER_SITES?=   https://github.com/nextcloud-releases/spreed/releases/download/${DISTVERSIONPREFIX}${PORTVERSION}/

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Online meeting app for Nextcloud
WWW=		https://nextcloud.com/talk/

LICENSE_FILE=	${WRKSRC}/COPYING

NEXTCLOUD_RUN_DEPENDS=	32

WRKSRC=		${WRKDIR}/spreed
WWWDIR=		${NEXTCLOUD_APPSDIR}/spreed

USES=		cpe nextcloud php:flavors

CPE_VENDOR=	nextcloud

.include <bsd.port.mk>
