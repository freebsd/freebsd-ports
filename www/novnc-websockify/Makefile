# $FreeBSD$

PORTNAME=	websockify
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	noVNC-websockify implementation.

LICENSE=	LGPL3 MPL20 BSD2CLAUSE BSD3CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/docs/LICENSE.LGPL-3

RUN_DEPENDS=	novnc>0:www/novnc

USES=		shebangfix python
SHEBANG_FILES=	run

USE_GITHUB=	yes
GH_ACCOUNT=	novnc
GH_PROJECT=	websockify
GH_TAGNAME=	1f132f9

NO_BUILD=	yes
NO_ARCH=	yes
TARGET_DIR=	${PREFIX}/libexec/novnc/utils/websockify

do-install:
	@${MKDIR} ${STAGEDIR}${TARGET_DIR}
	cd ${WRKSRC} && ${RM} .gitignore .gitmodules .travis.yml
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${TARGET_DIR}
	@${CHMOD} +x ${STAGEDIR}${TARGET_DIR}/run
	@${CHMOD} +x ${STAGEDIR}${TARGET_DIR}/rebind

.include <bsd.port.mk>
