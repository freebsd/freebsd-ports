PORTNAME=	forms
PORTVERSION=	3.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES=	https://github.com/nextcloud/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${PORTVERSION}/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	nextcloud/${PORTNAME}-${PORTVERSION}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Forms app for Nextcloud
WWW=		https://apps.nextcloud.com/apps/forms

LICENSE_FILE=	${WRKSRC}/COPYING

NEXTCLOUD_RUN_DEPENDS=	25

USES=		nextcloud php:flavors

.include <bsd.port.mk>
