PORTNAME=	memories
PORTVERSION=	8.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www graphics
MASTER_SITES?=	https://github.com/pulsejet/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${PORTVERSION}/
DISTNAME=	${PORTNAME}

MAINTAINER=	skozlov@FreeBSD.org
COMMENT=	Photo Management for Nextcloud
WWW=		https://apps.nextcloud.com/apps/${PORTNAME}

LICENSE_FILE=	${WRKSRC}/COPYING

NEXTCLOUD_RUN_DEPENDS=	33

USES=		nextcloud php:flavors

.include <bsd.port.mk>
