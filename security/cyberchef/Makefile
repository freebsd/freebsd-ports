# Created by: Dan Langille <dvl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cyberchef
PORTVERSION=	8.13.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Cyber operations within a web browser

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	gchq
GH_PROJECT=	CyberChef

NO_BUILD=       yes
NO_ARCH=        yes

do-install:
	(cd ${WRKSRC}/src/web/static && ${COPYTREE_SHARE} images       ${STAGEDIR}${WWWDIR}/)
	${INSTALL} ${WRKSRC}/src/web/html/index.html                   ${STAGEDIR}${WWWDIR}/
	

.include <bsd.port.mk>
