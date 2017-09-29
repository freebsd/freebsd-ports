# $FreeBSD$

PORTNAME=	websockify
PORTVERSION=	0.8.0
CATEGORIES=	www

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	noVNC-websockify implementation.

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	novnc>0:www/novnc

USES=		shebangfix python

USE_GITHUB=	yes
GH_ACCOUNT=	novnc
GH_PROJECT=	websockify
GH_TAGNAME=	1f132f9

NO_BUILD=	yes
NO_ARCH=	yes
TARGET_DIR=	${PREFIX}/libexec/novnc/utils/websockify

do-install:
	${MKDIR} ${STAGEDIR}${TARGET_DIR}
	cd ${WRKSRC} && ${RM} .gitignore .gitmodules .travis.yml
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${TARGET_DIR}
	@${CHMOD} +x ${STAGEDIR}${TARGET_DIR}/run
	@${CHMOD} +x ${STAGEDIR}${TARGET_DIR}/rebind

.include <bsd.port.mk>
