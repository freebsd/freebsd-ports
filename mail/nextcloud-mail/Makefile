PORTNAME=	mail
PORTVERSION=	5.1.5
DISTVERSIONPREFIX=	v
CATEGORIES=	mail

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Mail app for Nextcloud
WWW=		https://apps.nextcloud.com/apps/mail

LICENSE_FILE=	${WRKSRC}/COPYING

NEXTCLOUD_RUN_DEPENDS=	30

USES=		cpe gettext nextcloud php:flavors
USE_PHP=	imap

CPE_VENDOR=	nextcloud

.include <bsd.port.mk>
