# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fancybox
PORTVERSION=	2.1.5
CATEGORIES=	www
MASTER_SITES=	GH

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JavaScript library for image/html/multimedia content display

NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	fancyapps
GH_PROJECT=	fancyBox
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	18d1712

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC}/source/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

.include <bsd.port.mk>
