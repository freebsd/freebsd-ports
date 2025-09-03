PORTNAME=	appointments
PORTVERSION=	2.4.6
CATEGORIES=	www
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/raw/${DISTVERSIONPREFIX}${DISTVERSION}/build/artifacts/appstore/
DISTVERSIONPREFIX=	v
DISTNAME=	${PORTNAME}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Appointments app for Nextcloud
WWW=		https://apps.nextcloud.com/apps/appointments

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

NEXTCLOUD_RUN_DEPENDS=	29

USES=		nextcloud php:flavors

GH_ACCOUNT=	SergeyMosin

.include <bsd.port.mk>
