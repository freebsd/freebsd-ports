PORTNAME=	fancybox
PORTVERSION=	3.5.7
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JavaScript library for image/html/multimedia content display

LICENSE=	GPLv3

NO_ARCH=	yes
NO_BUILD=	yes

GH_ACCOUNT=	fancyapps
USE_GITHUB=	yes

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC}/dist/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

.include <bsd.port.mk>
