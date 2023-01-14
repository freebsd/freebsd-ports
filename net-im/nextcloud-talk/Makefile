PORTNAME=	talk
PORTVERSION=	15.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-im www
DISTNAME=	spreed-${DISTVERSIONPREFIX}${DISTVERSION}
DIST_SUBDIR=	nextcloud

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Online meeting app for Nextcloud
WWW=		https://nextcloud.com/talk/

LICENSE_FILE=	${WRKSRC}/COPYING

NEXTCLOUD_RUN_DEPENDS=	25

WRKSRC=		${WRKDIR}/spreed

USES=		cpe nextcloud php:flavors

CPE_VENDOR=	nextcloud

.include <bsd.port.mk>
