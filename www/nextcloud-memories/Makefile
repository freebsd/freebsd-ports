PORTNAME=	memories
PORTVERSION=	9.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www graphics
MASTER_SITES?=	https://github.com/pulsejet/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${PORTVERSION}/
DISTNAME=	${PORTNAME}

MAINTAINER=	skozlov@FreeBSD.org
COMMENT=	Photo Management for Nextcloud
WWW=		https://apps.nextcloud.com/apps/${PORTNAME}

LICENSE_FILE=	${WRKSRC}/COPYING

NEXTCLOUD_RUN_DEPENDS=	34

USES=		nextcloud php:flavors

.include <bsd.port.mk>
