PORTNAME=	news
PORTVERSION=	28.6.0
CATEGORIES=	www
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
DISTNAME=	${PORTNAME}

MAINTAINER=	nomoo@nomoo.ru
COMMENT=	News app for Nextcloud
WWW=		https://apps.nextcloud.com/apps/news

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

NEXTCLOUD_RUN_DEPENDS=	32

USES=		cpe nextcloud php:flavors

GH_ACCOUNT=	nextcloud

CPE_VENDOR=	nextcloud

.include <bsd.port.mk>
