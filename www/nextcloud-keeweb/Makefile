PORTNAME=	keeweb
PORTVERSION=	0.6.28
CATEGORIES=	www security
MASTER_SITES?=	https://github.com/jhass/${PKGNAMEPREFIX}${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	skozlov@FreeBSD.org
COMMENT=	Open Keepass stores inside Nextcloud
WWW=		https://apps.nextcloud.com/apps/${PORTNAME}

LICENSE_FILE=	${WRKSRC}/COPYING

NEXTCLOUD_RUN_DEPENDS=	34

USES=		nextcloud php:flavors

.include <bsd.port.mk>
