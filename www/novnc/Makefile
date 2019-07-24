# $FreeBSD$

PORTNAME=	novnc
PORTVERSION=	1.1.0
CATEGORIES=	www

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	HTML5 VNC client

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	novnc
GH_PROJECT=	noVNC
GH_TAGNAME=	e8986fa

NO_BUILD=	yes
NO_ARCH=	yes
TARGET_DIR=	${PREFIX}/libexec/novnc

do-install:
	${MKDIR} ${STAGEDIR}${TARGET_DIR}
	cd ${WRKSRC} && ${RM} .gitignore .gitmodules .travis.yml
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${TARGET_DIR}
	

.include <bsd.port.mk>
