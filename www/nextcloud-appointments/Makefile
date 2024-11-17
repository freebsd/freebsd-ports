PORTNAME=	appointments
PORTVERSION=	2.2.0
CATEGORIES=	www
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/raw/${DISTVERSIONPREFIX}${DISTVERSION}a/build/artifacts/appstore/
DISTVERSIONPREFIX=	v
DISTNAME=	${PORTNAME}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Appointments app for Nextcloud
WWW=		https://apps.nextcloud.com/apps/appointments

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

NEXTCLOUD_RUN_DEPENDS=	28

USES=		nextcloud php:flavors

GH_ACCOUNT=	SergeyMosin

.include <bsd.port.mk>
