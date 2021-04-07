PORTNAME=	websockify
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Websockify implementation for noVNC

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	novnc>0:www/novnc \
		${PYNUMPY}

USES=		python shebangfix python

SHEBANG_FILES=	run

USE_GITHUB=	yes
GH_ACCOUNT=	novnc
GH_PROJECT=	websockify

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
