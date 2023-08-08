PORTNAME=	tasks
PORTVERSION=	0.15.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES?=	https://github.com/nextcloud/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${PORTVERSION}/
DISTNAME=	${PORTNAME}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Tasks app for Nextcloud
WWW=		https://apps.nextcloud.com/apps/tasks

LICENSE_FILE=	${WRKSRC}/LICENSE

NEXTCLOUD_RUN_DEPENDS=	25

USES=		nextcloud php:flavors

.include <bsd.port.mk>
