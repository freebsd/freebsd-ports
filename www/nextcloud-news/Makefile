PORTNAME=	news
PORTVERSION=	27.0.0
CATEGORIES=	www
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
DISTNAME=	${PORTNAME}

MAINTAINER=	nomoo@nomoo.ru
COMMENT=	News app for Nextcloud
WWW=		https://apps.nextcloud.com/apps/news

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

NEXTCLOUD_RUN_DEPENDS=	30

USES=		nextcloud php:flavors

GH_ACCOUNT=	nextcloud

.include <bsd.port.mk>
