# Created by: Dan Langille <dvl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cyberchef
PORTVERSION=	0.0.0.20170124
CATEGORIES=	security

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Cyber operations within a web browser

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	gchq
GH_PROJECT=	CyberChef
GH_TAGNAME=	3c3f5d9

NO_BUILD=       yes
NO_ARCH=        yes

do-install:
	(cd ${WRKSRC}/build/prod && ${COPYTREE_SHARE} \*       ${STAGEDIR}${WWWDIR}/)
	(cd ${WRKSRC}/build/prod && ${INSTALL_DATA}  .htaccess ${STAGEDIR}${WWWDIR}/)

.include <bsd.port.mk>
