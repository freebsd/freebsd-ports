# $FreeBSD$

PORTNAME=	novnc
PORTVERSION=	1.2.0
CATEGORIES=	www

MAINTAINER=	dpetrov67@gmail.com
COMMENT=	HTML5 VNC client

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	novnc
GH_PROJECT=	noVNC
GH_TAGNAME=	9142f8f

NO_BUILD=	yes
NO_ARCH=	yes
TARGET_DIR=	${PREFIX}/libexec/novnc

post-extract:
	@cd ${WRKSRC} && ${RM} .gitignore .gitmodules .travis.yml .eslintignore
	@cd ${WRKSRC} && ${RM} -R .github
	@cd ${WRCSRC} && ${FIND} ${WRKSRC} -name '.eslintrc' -delete

do-install:
	${MKDIR} ${STAGEDIR}${TARGET_DIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${TARGET_DIR}

.include <bsd.port.mk>
