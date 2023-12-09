PORTNAME=	notes
PORTVERSION=	4.9.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www editors
MASTER_SITES=	https://github.com/nextcloud/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${PORTVERSION}/
DISTNAME=	${PORTNAME}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Notes app for Nextcloud
WWW=		https://apps.nextcloud.com/apps/notes

LICENSE_FILE=	${WRKSRC}/COPYING

NEXTCLOUD_RUN_DEPENDS=	25

USES=		nextcloud php:flavors

.include <bsd.port.mk>
