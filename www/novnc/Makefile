PORTNAME=	novnc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
CATEGORIES=	www

MAINTAINER=	dpetrov67@gmail.com
COMMENT=	HTML5 VNC client
WWW=		https://github.com/novnc/noVNC

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cpe

USE_GITHUB=	yes
GH_PROJECT=	noVNC

EXTRACT_AFTER_ARGS=	--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/.gitignore \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/.gitmodules \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/.github \
			--no-same-owner --no-same-permissions

NO_ARCH=	yes
NO_BUILD=	yes
TARGET_DIR=	${PREFIX}/libexec/novnc

do-install:
	${MKDIR} ${STAGEDIR}${TARGET_DIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${TARGET_DIR})

.include <bsd.port.mk>
