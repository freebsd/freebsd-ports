# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fancybox
PORTVERSION=	2.1.6
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JavaScript library for image/html/multimedia content display

NO_ARCH=	yes
NO_BUILD=	yes
USES=		cpe

GH_ACCOUNT=	fancyapps
GH_PROJECT=	fancyBox
USE_GITHUB=	yes

CPE_VENDOR=	fancybox_project

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC}/source/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

.include <bsd.port.mk>
